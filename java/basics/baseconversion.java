import java.util.*;
import java.math.*;
class baseconversion{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();

    int y = sc.nextInt();
    String str = sc.nextLine();
    str = sc.nextLine();
    System.out.println(new BigInteger(str,x).toString(y));
  }
}