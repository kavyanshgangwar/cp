import java.util.*;
class pi{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    System.out.printf("%."+String.valueOf(n)+"f\n",Math.PI);
  }
}