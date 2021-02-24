import java.util.*;
class bitset{
  public static void main(String args[]){
    BitSet b = new BitSet();
    
    b.set(2);
    System.out.println(b);
    BitSet a = new BitSet();
    a.set(1);
    b.or(a);
    System.out.println(b);
    b.andNot(a);
    System.out.println(b);
  }
}