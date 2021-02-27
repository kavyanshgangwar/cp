import java.util.*;
class uniquesorted{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Set<Integer> a = new TreeSet<Integer>();
    for(int i=0;i<n;i++){
      a.add(sc.nextInt());
    }
    for(int x:a){
      System.out.printf("%d ",x);
    }
    System.out.println(" ");
  }
}
