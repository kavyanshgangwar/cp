import java.util.*;
import java.io.*;
// this fenwick tree is for range update and point query
class FenwickTree{
  private int[] ft;
  public FenwickTree(int n){
    ft = new int[n];
  }
  private int LSOne(int a){
    return (a&(-a));
  }
  private void adjust(int k,int value){
    for(;k<ft.length;k+=LSOne(k))ft[k]+=value;
  }
  public void range_update(int l,int r,int value){
    this.adjust(l,value);
    this.adjust(r+1,-1*value);
  }
  public int rsq(int a){
    int ans=0;
    for(;a>0;a-=LSOne(a)){
      ans+=ft[a];
    }
    return ans;
  }
}
class fenwicktree{
  public static void main(String args[])throws IOException{
    BufferedReader r =  new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    FenwickTree f = new FenwickTree(n);
    for(int i=0;i<n;i++){
      f.range_update(i+1,i+1,Integer.parseInt(r.readLine()));
    }
    System.out.println(f.rsq(2));
    f.range_update(1,5,10);
    System.out.println(f.rsq(2));
    System.out.println(f.rsq(8));
  }
}