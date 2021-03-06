import java.util.*;
import java.io.*;
class UFDS{
  public int[] parent;
  public int[] rank;
  public UFDS(int n){
    parent = new int[n];
    rank = new int[n];
    for(int i=0;i<n;i++){
      parent[i]=i;
    }
  }
  public int findParent(int x){
    if(parent[x]==x){
      return x;
    }else{
      parent[x] = findParent(parent[x]);
    }
    return parent[x];
  }
  public void union(int x,int y){
    x = findParent(x);
    y = findParent(y);
    if(x!=y){
      if(rank[x]>rank[y]){
        parent[y]=x;
      }else{
        parent[x]=y;
        if(rank[x]==rank[y]){
          rank[y]++;
        }
      }
    }
  }
}
class Edge{
  public int u;
  public int v;
  public int weight;
  Edge(int a,int b,int w){
    u = a;
    v = b;
    weight =w;
  }
}
class sortByWeight implements Comparator<Edge>{
  public int compare(Edge e,Edge b){
    if(e.weight>b.weight){
      return 1;
    }else if(e.weight<b.weight){
      return -1;
    }else{
      return 0;
    }
  }
}
class krushkal{
  public static void main(String args[])throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter p = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    int m = Integer.parseInt(r.readLine());
    UFDS uf = new UFDS(n);
    ArrayList<Edge> e = new ArrayList<>();
    int cnt = 0;
    for(int i=0;i<m;i++){
      String[] x = (r.readLine()).split(" ");
      e.add(new Edge(Integer.parseInt(x[0]),Integer.parseInt(x[1]),Integer.parseInt(x[2])));
    }
    Collections.sort(e,new sortByWeight());
    int sm=0;
    for(int i=0;i<m;i++){
      if(uf.findParent(e.get(i).u)!=uf.findParent(e.get(i).v)){
        cnt++;
        // p.printf("%d\n",e.get(i).weight);
        uf.union(e.get(i).u,e.get(i).v);
        sm+=e.get(i).weight;
      }
      if(cnt==n-1){
        break;
      }
    }
    p.printf("%d\n",sm);
    p.close();
  }
}