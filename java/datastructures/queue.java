import java.util.*;
import java.io.*;
class queue{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    Queue<Double> q = new LinkedList<>();
    while(q.size()<n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          q.add(Double.parseDouble(x));
        }
      }
    }
    while(q.size()!=0){
      System.out.printf("%.9f\n",q.remove());
    }
  }
}