#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[2010];
const int mod = 1000000007;
int a[2010];
int n,d;
int f(int u,int mn,int p,int root){
  int ans = 1;
  for(int i=0;i<g[u].size();i++){
    if(g[u][i]!=p && a[g[u][i]]>=mn && a[g[u][i]]<=(mn+d)){
      if(a[g[u][i]]==mn && g[u][i]<root){
        continue;
      }
      ans = (ans%mod * (f(g[u][i],mn,u,root)%mod + 1)%mod)%mod;
    }
  }
  return ans%mod;
}
signed main(){
  cin>>d>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int u,v;
  for(int i=0;i<n-1;i++){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = (ans%mod + f(i,a[i],0,i)%mod)%mod;
    // cout<<"i: "<<i<<" value: "<<ans<<endl;
  }
  cout<<ans%mod<<endl;
}