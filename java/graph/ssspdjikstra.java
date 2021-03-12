import java.util.*;
import java.io.*;
class Pair implements Comparable<Pair>{
  public int first;
  public int second;
  public Pair(int a,int b){
    this.first = a;
    this.second = b;
  }
  public int compareTo(Pair b){
    if(this.first<b.first){
      return 1;
    }else if(this.first>b.first){
      return -1;
    }else{
      if(this.second <b.second){
        return 1;
      }else if(this.second>b.second){
        return -1;
      }else{
        return 0;
      }
    }
  }
}

class ssspdjikstra{
  public static void main(String[] args)throws IOException{
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int INF = 1000000;
    ArrayList<ArrayList<Pair> > graph = new ArrayList<>();
    for(int i=0;i<n+1;i++){
      graph.add(new ArrayList<Pair>());
    }
    for(int i=0;i<n;i++){
      int a,b,w;
      a = s.nextInt();
      b=s.nextInt();
      w = s.nextInt();
      graph.get(a).add(new Pair(b,w));
    }
    PriorityQueue<Pair> pq = new PriorityQueue<>();
    pq.add(new Pair(0,2));
    ArrayList<Integer> dist = new ArrayList<Integer>();
    for(int i=0;i<n+1;i++){
      dist.add(INF);
    }
    while(pq.size()!=0){
      int a = pq.peek().first;
      int b = pq.poll().second;
      if(dist.get(b)<a){
        continue;
      }
      dist.set(b,a);
      for(int i=0;i<graph.get(b).size();i++){
        if(a+graph.get(b).get(i).second<dist.get(graph.get(b).get(i).first)){
          dist.set(graph.get(b).get(i).first,a+graph.get(b).get(i).second);
          pq.add(new Pair(a+graph.get(b).get(i).second,graph.get(b).get(i).first));
        }
      }
    }
    for(int i=0;i<n+1;i++){
      System.out.printf("%d ",dist.get(i));
    }
  }
}