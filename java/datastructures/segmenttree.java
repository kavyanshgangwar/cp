import java.util.*;
import java.io.*;
class SegmentTree{
  private int[] st;
  private int[] lazy;
  private int[] a;
  private int n;
  
  private void build(int p,int l,int r){
    if(l==r){
      st[p]=a[l];
    }else{
      build(p<<1,l,(l+r)/2);
      build((p<<1)+1,(l+r)/2+1,r);
      st[p] = st[p<<1]+st[(p<<1)+1];
    }
  }

  public SegmentTree(int[] A){
    a = A;
    n = A.length;
    st = new int[4*n];
    lazy = new int[4*n];
    build(1,0,n-1);
  }

  private int rsq(int p,int i,int j,int l,int r){
    if(lazy[p]!=0){
      st[p]+=(lazy[p]*(r-l+1));
      if(l!=r){
        lazy[p<<1]+=lazy[p];
        lazy[(p<<1)+1]+=lazy[p];
      }
      lazy[p]=0;
    }
    if(i>r || j<l){
      return 0;
    }
    if(i<=l && j>=r){
      return st[p];
    }
    return (rsq(p<<1,i,j,l,(l+r)/2)+rsq((p<<1)+1,i,j,(l+r)/2+1,r));
  }

  public int rsq(int i,int j){
    return rsq(1,i,j,0,n-1);
  }

  private void update(int p,int i,int l,int r){
    if(lazy[p]!=0){
      st[p]+=(lazy[p]*(r-l+1));
      if(l!=r){
        lazy[p<<1]+=lazy[p];
        lazy[(p<<1)+1]+=lazy[p];
      }
      lazy[p]=0;
    }
    if(i>r || i<l){
      return;
    }
    if(i==l && i==r){
      st[p]=a[l];
    }else{
      update(p<<1,i,l,(l+r)/2);
      update((p<<1)+1,i,(l+r)/2+1,r);
      st[p]=st[p<<1]+st[(p<<1)+1];
    }
  }

  public void update(int i,int value){
    a[i]=value;
    update(1,i,0,n-1);
  }

  private void updateRange(int p,int i,int j,int l,int r,int value){
    if(lazy[p]!=0){
      st[p]+=(lazy[p]*(r-l+1));
      if(l!=r){
        lazy[p<<1]+=lazy[p];
        lazy[(p<<1)+1]+=lazy[p];
      }
      lazy[p]=0;
    }
    if(i>r || j<l){
      return;
    }
    if(i<=l && j>=r){
      if(l!=r){
        lazy[p<<1]+=value;
        lazy[(p<<1)+1]+=value;
      }
      st[p]+=(value*(r-l+1));
      return;
    }
    updateRange(p<<1,i,j,l,(l+r)/2,value);
    updateRange((p<<1)+1,i,j,(l+r)/2+1,r,value);
    st[p]=st[p<<1]+st[(p<<1)+1];
  }

  public void updateRange(int i,int j,int value){
    updateRange(1,i,j,0,n-1,value);
  }
}
class segmenttree{
  public static void main(String args[]) throws IOException{
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(r.readLine());
    int[] a = new int[n];
    int cnt = 0;
    while(cnt!=n){
      String[] s = r.readLine().split(" ");
      for(String x:s){
        if(!x.equals("")){
          a[cnt] = Integer.parseInt(x);
          cnt++;
        }
      }
    }
    SegmentTree s = new SegmentTree(a);
    System.out.println(s.rsq(0,4));
    s.updateRange(2,4,10);
    System.out.println(s.rsq(0,4));
    s.update(2,3);
    System.out.println(s.rsq(0,4));
  }
}