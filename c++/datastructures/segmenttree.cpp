#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
  private:
    vector<int> st;
    vector<int> A;
    vector<int> lazy;
    int n;
    void build(int p,int l,int r){
      if(l==r){
        st[p]=A[l];
      }else{
        build(p<<1,l,(l+r)/2);
        build((p<<1)+1,(l+r)/2+1,r);
        st[p] = min(st[p<<1],st[(p<<1)+1]);
      }
    }
    int rmq(int p,int i,int j,int l,int r){
      if(lazy[p]){
        st[p]+=lazy[p];
        if(l!=r){
          lazy[p<<1]+=lazy[p];
          lazy[(p<<1)+1]+=lazy[p];
        }
        lazy[p]=0;
      }
      if(i>r || j<l){
        return INT32_MAX;
      }else{ 
        if(i<=l && j>=r){
          return st[p];
        }else{
          return min(rmq(p<<1,i,j,l,(l+r)/2),rmq((p<<1)+1,i,j,(l+r)/2+1,r));
        }
      }
    }
    void update(int p,int i,int l,int r){
      if(lazy[p]){
        st[p]+=lazy[p];
        if(l!=r){
          lazy[p<<1]+=lazy[p];
          lazy[(p<<1)+1]+=lazy[p];
        }
        lazy[p]=0;
      }
      if(i==l && i==r){
        st[p]=A[i];
      }else{
        if(i<l || i>r){
          return;
        }
        update(p<<1,i,l,(l+r)/2);
        update((p<<1)+1,i,(l+r)/2+1,r);
        st[p] = min(st[p<<1],st[(p<<1)+1]);
      }
    }
    void updateRange(int p,int i,int j,int l,int r,int value){
      if(lazy[p]){
        st[p]+=lazy[p];
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
        st[p]+=value;
      }else{
        updateRange(p<<1,i,j,l,(l+r)/2,value);
        updateRange((p<<1)+1,i,j,(l+r)/2+1,r,value);
        st[p]=min(st[p<<1],st[(p<<1)+1]);
      }
    }
  public:
    void update(int i,int value){
      A[i]=value;
      update(1,i,0,n-1);
    }
    SegmentTree(const vector<int> &a){
      A = a;
      n = a.size();
      lazy.assign(4*n,0);
      st.assign(4*n,0);
      build(1,0,n-1);
    }
    int rmq(int i,int j){
      return rmq(1,i,j,0,n-1);
    }
    void printtree(){
      for(int x:st){
        cout<<x<<" ";
      }
      cout<<endl;
    }
    void updateRange(int i,int j,int value){
      updateRange(1,i,j,0,n-1,value);
    }
};
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  SegmentTree s = SegmentTree(v);
  cout<<s.rmq(1,4)<<endl;
  s.updateRange(2,4,10);
  cout<<s.rmq(1,4)<<endl;
  s.update(2,50);
  cout<<s.rmq(1,4)<<endl;
  s.printtree();
}