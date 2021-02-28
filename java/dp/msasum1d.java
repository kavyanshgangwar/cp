import java.util.*;
import java.io.*;
class msasum1d{
  public static void main(String args[])throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    int[] a = new int[n];
    int i=0;
    while(i<n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          a[i]=Integer.parseInt(x);
          i++;
        }
      }
    }
    int sum = 0;
    int ans = 0;
    for(i=0;i<n;i++){
      sum+=a[i];
      ans=Math.max(ans,sum);
      if(sum<0)sum=0;
    }
    w.printf("%d\n",ans);
    w.close();
  }
}