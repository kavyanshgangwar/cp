import java.util.*;
import java.io.*;
class set{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    Set<Integer> st =  new TreeSet<>();
    while(st.size()!=n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          st.add(Integer.parseInt(x));
        }
      }
    }
    for(int x:st){
      System.out.println(x);
    }
  }
}