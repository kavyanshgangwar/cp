import java.util.*;
import java.io.*;
class linkedlist{
  public static void main(String args[]) throws IOException{
    BufferedReader reader= new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(reader.readLine());
    LinkedList<Integer> l =  new LinkedList<>();
    while(l.size()!=n){
      String[] s = reader.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          l.add(Integer.parseInt(x));
        }
      }
    }
    for(int x:l){
      System.out.println(x);
    }
  }
}