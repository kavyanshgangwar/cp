import java.util.*;
import java.util.Collections.*;
// import org.javatuples.Triplet;
class BirthDate implements Comparable<BirthDate>{
  public int day,month,year;
  BirthDate(int day,int month,int year){
    this.day = day;
    this.month = month;
    this.year = year;
  }
  @Override
  public int compareTo(BirthDate b){
    if(this.month<b.month){
      return -1;
    }else{
      if(this.day<b.day){
        return -1;
      }else{
        if(this.year<b.year){
          return -1;
        }else{
          return 1;
        }
      }
    }
    
  }
  @Override
  public String toString(){
    return String.valueOf(this.day)+" "+String.valueOf(this.month)+" "+String.valueOf(this.year);
  }
}
class birthdates{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    List<BirthDate> l = new ArrayList<BirthDate>();
    for(int i=0;i<n;i++){
      l.add(new BirthDate(sc.nextInt(),sc.nextInt(),sc.nextInt()));
    }
    System.out.println("");
    Collections.sort(l);
    for(BirthDate x: l){
      System.out.println(x);
    }


    // another way
    // List<Triplet<Integer,Integer,Integer> > b = new ArrayList<>();
    // for(int i=0;i<n;i++){
    //   int d,m;
    //   d=sc.nextInt();
    //   m=sc.nextInt();
    //   b.add(Triplet.with(m,d,sc.nextInt()));
    // }
    // sort(b);
    // for(Triplet x:b){
    //   System.out.printf("%d ",x.getValue(1));
    //   System.out.printf("%d ",x.getValue(0));
    //   System.out.printf("%d ",x.getValue(2));
      
    // }

  }
}