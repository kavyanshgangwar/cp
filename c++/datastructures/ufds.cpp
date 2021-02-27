#include <bits/stdc++.h>
using namespace std;
class UFDS{
  private:
    vector<int> p,rank;
  public:
    UFDS(int n){
      p.assign(n,0);
      rank.assign(n,0);
      for(int i=0;i<n;i++)p[i]=i;
    }
    int findSet(int i){
      return (p[i]==i)?i:(p[i]=findSet(p[i]));
    }
    bool isSameSet(int a,int b){
      return findSet(a)==findSet(b);
    }
    void unionSet(int a,int b){
      if(isSameSet(a,b))return;
      int x = findSet(a);
      int y = findSet(b);
      if(rank[x]>rank[y]){
        p[y]=x;
      }else{
        p[x]=y;
        if(rank[x]==rank[y]){
          rank[y]++;
        }
      }
    }
};
int main(){
  int n;
  cin>>n;
  UFDS u = UFDS(n);
  cout<<u.findSet(0);
  u.unionSet(0,1);
  cout<<u.findSet(1);
  u.unionSet(0,2);
  cout<<u.findSet(2);
}