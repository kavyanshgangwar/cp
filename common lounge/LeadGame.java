import java.util.*;
import java.io.*;
class LeadGame{
  public static void main(String[] args) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter p = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    int[] a = new int[n+1];
    int[] b = new int[n+1];
    a[0]=b[0]=0;
    int mx = 0;
    for(int i=1;i<=n;i++){
      String[] s = r.readLine().split(" ");
      a[i]=Integer.parseInt(s[0]);
      b[i]=Integer.parseInt(s[1]);
      a[i]+=a[i-1];
      b[i]+=b[i-1];
      if(Math.abs(mx)<Math.abs(a[i]-b[i])){
        mx=a[i]-b[i];
      }
    }
    if(mx<0){
      p.printf("2 %d\n",Math.abs(mx));
    }else{
      p.printf("1 %d\n",Math.abs(mx));
    }
    p.close();
  }
}