import java.util.*;
import javax.script.*;
class scriptengine{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    ScriptEngineManager sem = new ScriptEngineManager();
    ScriptEngine se = sem.getEngineByName("JavaScript");
    while(sc.hasNextLine()){ 
      try{
        System.out.println(se.eval(sc.nextLine()));
      }catch(Exception e){
        e.printStackTrace();
      }
    }
  }
}