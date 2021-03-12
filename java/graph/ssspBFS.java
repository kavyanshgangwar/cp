import java.util.*;
import java.io.*;
class ssspBFS{
  public static void main(String[] args)throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    Vector<Vector<Integer> > v = new Vector<Vector<Integer>>(n);
    for(int i=0;i<n;i++){
      v.add(i,new Vector<Integer>());
    }
    int m = Integer.parseInt(r.readLine());
    for(int i=0;i<m;i++){
      String[] x = r.readLine().split(" ");
      v.get(Integer.parseInt(x[0])).add(Integer.parseInt(x[1]));
      v.get(Integer.parseInt(x[1])).add(Integer.parseInt(x[0]));
    }
    Queue<Integer> q = new LinkedList<Integer>();
    q.add(0);
    boolean[] vis = new boolean[n+1];
    vis[0] = true;
    int[] parent = new int[n+1];
    while(q.size()>0){
      int u = q.poll();
      for(int i=0;i<v.get(u).size();i++){
        if(!vis[v.get(u).get(i)]){
          q.add(v.get(u).get(i));
          vis[v.get(u).get(i)]=true;
          parent[v.get(u).get(i)]=u;
        }
      }
    }
    for(int i=0;i<n;i++){
      w.printf("%d -> %d\n",i,parent[i]);
    }
    w.close();
  }
}