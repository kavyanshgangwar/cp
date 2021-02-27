import java.util.*;
import java.io.*;
// this FenwickTree is for range update and range queries
class FenwickTree{
  private int[][] ft;
  private int LSOne(int k){return (k&-k);}
  public FenwickTree(int n){
    ft = new int[2][n+1];
  }
  private void adjust(int i,int k,int value){
    for(;k<ft[i].length;k+=LSOne(k)){
      ft[i][k]+=value;
    }
  }
  public void rangeUpdate(int i,int j,int value){
    adjust(0,i,value);
    adjust(0,j+1,-value);
    adjust(1,i,value*(i-1));
    adjust(1,j+1,-value*j);
  }
  private int rsq(int i,int k){
    int ans=0;
    for(;k>0;k-=LSOne(k)){
      ans+=ft[i][k];
    }
    return ans;
  }
  private int prefixSum(int k){
    return (k*rsq(0,k)-rsq(1,k));
  }
  public int rsQuery(int a,int b){
    if(a>1) return (prefixSum(b)-prefixSum(a-1));
    else return prefixSum(b);
  }
}
class fenwicktreerange{
  public static void main(String args[])throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    FenwickTree f = new FenwickTree(n);
    for(int i=0;i<n;i++){
      f.rangeUpdate(i+1,i+1,Integer.parseInt(r.readLine()));
    }
    System.out.println(f.rsQuery(1,3));
    f.rangeUpdate(2,4,10);
    System.out.println(f.rsQuery(1,3));
    System.out.println(f.rsQuery(1,5));
  }
}