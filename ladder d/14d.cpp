#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
vector<int> v[210];
int f0(int u,int p){
  int h = 0;
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      h = max(h,f0(v[u][i],u));
    }
  }
  return h+1;
}
int f1(int u,int p){
  vector<int> h;
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      h.push_back(f0(v[u][i],u));
    }
    

  }
  sort(h.begin(),h.end(),greater<int>());
  if(h.size()>1)
  return h[0]+h[1];
  else
  return h[0];
}
int main(){
  int n;
  cin>>n;
  int a,b;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    vector<pair<int,int> > h;
    for(int j=0;j<v[i].size();j++){
      h.push_back({f1(v[i][j],i),f0(v[i][j],i)});
    }
    sort(h.begin(),h.end(),greater<pair<int,int> > ());
    // cout<<h.size()<<endl;
    if(i==6){
      for(auto x:h){
        cout<<x.f<<" "<<x.s<<" ";
      }
      cout<<endl;
    }
    if(h.size()>2){
      ans = max(ans,(h[0].f)*(h[1].s+h[2].s));
      cout<<ans<<endl;
    }else if(h.size()==2){
      ans =max(ans,(h[0].f)*(h[1].s));
    }else if(h.size()==1){
      ans= max(ans,h[0].f*0);
    }
  }
  cout<<ans<<endl;
}