import java.util.*;
import java.io.*;
class IntegerPair{
  public int x,y;
  IntegerPair(int a,int b){
    x=a;
    y=b;
  }
}
class graph{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    int[][] am = new int[n][n];
    Vector<IntegerPair> edge =  new Vector<>();
    Vector<Vector<Integer> > al = new Vector<>(n);
    for(int i=0;i<n;i++){
      al.add(new Vector<Integer>());
    }
    int e = Integer.parseInt(r.readLine());
    for(int i=0;i<e;i++){
      String[] s = r.readLine().split(" ");
      int u = Integer.parseInt(s[0]);
      int v = Integer.parseInt(s[1]);
      edge.add(new IntegerPair(u,v));
      am[u-1][v-1]=1;
      am[v-1][u-1]=1;
      al.get(u-1).add(v-1);
      al.get(v-1).add(u-1);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        System.out.printf("%d ",am[i][j]);
      }
      System.out.printf("\n");
    }
    for(int i=0;i<n;i++){
      System.out.printf("%d: ",i+1);
      for(int x:al.get(i)){
        System.out.printf("%d ",x+1);
      }
      System.out.printf("\n");
    }
    for(IntegerPair x:edge){
      System.out.printf("%d %d",x.x,x.y);
      System.out.printf("\n");
    }
  }
}