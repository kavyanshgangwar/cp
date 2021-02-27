import java.util.*;
class dayofweek{
  public static void main(String args[]){
    String[] names = {"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    Scanner sc = new Scanner(System.in);
    int day,month, year;
    day = sc.nextInt();
    month = sc.nextInt();
    year = sc.nextInt();
    Calendar calander = new GregorianCalendar(year,month,day);
    System.out.println(names[calander.get(Calendar.DAY_OF_WEEK)]);
  }
}