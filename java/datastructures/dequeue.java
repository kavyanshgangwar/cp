import java.util.*;
import java.io.*;
class dequeue{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    Deque<Boolean> d = new ArrayDeque<>();
    while(d.size()<2*n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          d.add(Boolean.parseBoolean(x));
          d.addLast(Boolean.parseBoolean(x));
        }
      }
    }
    while(d.size()>0){
      System.out.println(d.removeLast());
      System.out.println(d.removeFirst());
    }
    System.out.println(Boolean.parseBoolean("1"));
  }
}