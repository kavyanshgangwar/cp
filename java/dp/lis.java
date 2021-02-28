import java.util.*;
import java.io.*;
class lis{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int n = Integer.parseInt(r.readLine());
    int[] a = new int[n];
    int i=0;
    while(i<n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          a[i]=Integer.parseInt(x);
          i++;
        }
      }
    }
    ArrayList<Integer> al = new ArrayList<>();
    for( i=0;i<n;i++){
      int index = Collections.binarySearch(al,a[i]);
      if(index<0){
        index++;
        index*=-1;
        if(index<al.size()){
          al.set(index,a[i]);
        }else{
          al.add(a[i]);
        }
      }
    }
    w.printf("%d\n",al.size());
    w.close();
  }
}