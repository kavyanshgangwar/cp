import java.util.*;
import java.io.*;
class msasum2d{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    int[][] a = new int[n][n];
    int i=0,j=0;
    while(i<n){
      j=0;
      while(j<n){
        String[] s = r.readLine().split(" ");
        for(String x:s){
          if(!x.equals("")){
            a[i][j] = Integer.parseInt(x);
            j++;
          }
        }
      }
      i++;
    }
    int sum =0;
    int ans = 0;
    for(i=0;i<n;i++){
      for(j=1;j<n;j++){
        a[i][j]+=a[i][j-1];
      }
    }
    for(i=0;i<n;i++){
      for(j=i;j<n-1;j++){
        sum=0;
        for(int k=0;k<n;k++){
          sum += (a[k][j+1]-((i>0)?a[k][i-1]:0));
          ans = Math.max(sum,ans);
          if(sum<0)sum=0;
        }
      }
    }
    w.printf("%d\n",ans);
    w.close();
  }
}