import java.util.*;
class allsubsets{
  public static int a=0;
  public static int cnt=0;
  public static void main(String args[]){
    subsets(0);
    System.out.printf("%d\n",cnt);
  }
  public static void subsets(int k){
    if(k==20){
      cnt++;
      // for(int i=0;i<20;i++){
      //   if((a&(1<<i))!=0){
      //     System.out.printf("%d ",i+1);
      //   }
      // }
      // System.out.printf("\n");
    }else{
      subsets(k+1);
      a=a^(1<<k);
      subsets(k+1);
      a=a^(1<<k);
    }
  }
}