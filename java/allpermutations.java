import java.util.*;
class allpermutations{
  public static int cnt=0;
  public static boolean[] vis = new boolean[10];
  public static int[] a = new int[10];
  public static void main(String args[]){
    for(int i=0;i<10;i++){
      vis[i]=false;
    }
    permutation(0);
    System.out.println(cnt);
  }
  public static void permutation(int k){
    if(k==10){
      // for(int i=0;i<10;i++){
      //   System.out.printf("%d ",a[i]);
      // }
      // System.out.printf("\n");
      cnt++;
    }else{
      for(int i=0;i<10;i++){
        if(!vis[i]){
          vis[i]=true;
          a[k]=i+1;
          permutation(k+1);
          vis[i]=false;
        }
      }
    }
  }
}