import java.util.*;
class binarysearch{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for(int i=0;i<n;i++){
      a[i]=sc.nextInt();

    }
    int i=n;
    int c = sc.nextInt();
    int j=0;
    while(i>0){
      while(i+j<n && a[i+j]<=c){
        j+=i;
      }
      i/=2;
    }
    System.out.println(j);
  }
}