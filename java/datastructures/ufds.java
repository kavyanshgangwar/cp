import java.util.*;
import java.io.*;
class UFDS{
  private int[] p;
  private int[] rank;
  //constructor
  public UFDS(int n){
    p = new int[n];
    rank = new int[n];
    for(int i=0;i<n;i++){
      p[i]=i;
    }
  }
  // findset
  public int findset(int a){
    return ((p[a]==a)?a:(p[a]=findset(p[a])));
  }

  //is same set
  public boolean isSameSet(int a,int b){
    return (findset(a)==findset(b));
  }

  // union
  public void union(int a,int b){
    if(isSameSet(a,b))return;
    int x = findset(a);
    int y = findset(b);
    if(rank[x]>rank[y]){
      p[y]=x;
    }else if(rank[y]>rank[x]){
      p[x]=y;
    }else{
      p[x]=y;
      rank[y]++;
    }
  }
}
class ufds{
  public static void main(String args[])throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    UFDS u=new UFDS(n);
    System.out.println(u.findset(0));
    u.union(0,1);
    System.out.println(u.findset(0));

  }
}