import java.util.*;
import java.io.*;
class array{
  public static void main(String args[]) throws IOException{
    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    int n=Integer.parseInt(sc.readLine());
    int[][] a = new int[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a[i][j]=n*i+j+1;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        System.out.printf("%d ",a[i][j]);
      }
      System.out.printf("\n");
    }
  }
}