import java.util.*;
import java.io.*;
class map{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    Map<String,Integer> m = new TreeMap<>();
    for(int i=0;i<n;i++){
      String[] s = r.readLine().split(" ");
      m.put(s[0],Integer.parseInt(s[1]));
    }
    for(int i=0;i<n;i++){
      String s = r.readLine();
      if(m.get(s)!=null){
        System.out.println(m.get(s));
      }else{
        System.out.println("Key not found!");
      }
    }
  }
}