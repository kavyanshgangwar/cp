import java.util.*;
import java.io.*;
class comp implements Comparator<Integer>{
  public int compare(Integer a,Integer b){
    if(a<b){
      return 1;
    }else if(b<a){
      return -1;
    }else{
      return 0;
    }
  }
}
class pq{
  public static void main(String args[])throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    PriorityQueue<Integer> pq = new PriorityQueue<>(new comp());
    while(pq.size()!=n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          pq.add(Integer.parseInt(x));
        }
      }
    }
    for(int i=0;i<n;i++){
      System.out.println(pq.poll());
    }
  }
}