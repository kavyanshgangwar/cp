import java.util.*;
import java.io.*;
class stack{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    Stack<Integer> s = new Stack<>();
    while(s.size()!=n){
      String[] temp = r.readLine().split(" ");
      for(String x:temp){
        if(!x.equals(""))s.push(Integer.parseInt(x));
      }
    }
    while(!s.empty()){
      System.out.println(s.pop());
    }
  }
}