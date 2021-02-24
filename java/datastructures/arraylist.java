import java.util.*;
import java.io.*;
class arraylist{
  public static void main(String args[]) throws IOException{
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(reader.readLine());
    List<Integer> v = new ArrayList();
    for(int i=0;i<n;i++){
      v.add(Integer.parseInt(reader.readLine()));
    }
    for(int i=0;i<n;i++){
      System.out.printf("%d ",v.get(i));
    }
    System.out.printf("\n");
  }
}