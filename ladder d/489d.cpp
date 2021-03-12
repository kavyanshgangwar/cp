#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v[3010];
int f(int u,int n){
  int cnt[n+1]={0};
  for(int i=0;i<v[u].size();i++){
    for(int j=0;j<v[v[u][i]].size();j++){
      if(v[v[u][i]][j]!=v[u][i] && v[v[u][i]][j]!=u){
        cnt[v[v[u][i]][j]]++;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans += ((cnt[i]*(cnt[i]-1))/2);
  }
  // cout<<ans<<" ";
  return ans;
}
signed main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int u,z;
    cin>>u>>z;
    v[u].push_back(z);
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    ans+=f(i,n);
  }
  cout<<ans<<endl;
}