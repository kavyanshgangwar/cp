#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int x[m];
  vector<int> y[2];
  
  string s;
  int p;
  for(int i=0;i<n;i++){
    cin>>s;
    cin>>p;
    if(s=="ATK"){
      y[0].push_back(p);
    }else{
      y[1].push_back(p);
    }
  }
  for(int i=0;i<m;i++){
    cin>>x[i];
  }
  sort(x,x+m);
  sort(y[0].begin(),y[0].end());
  sort(y[1].begin(),y[1].end());
  int f = y[0].size();
  int f1 = y[1].size();
  int ans=0;
  for(int i=1;i<=min(f,m);i++){
    int cnt = 0;
    for(int j=0;j<i;j++){
      cnt-=y[0][j];
    }
    for(int j=m-1;j>=m-i;j--){
      cnt+=x[j];
    }
    // cout<<cnt<<endl;
    ans=max(ans,cnt);
  }
  // cout<<ans<<endl;
  int vis[m]={0};
  int j=0;
  for(int i=0;i<m;i++){
    if(j==f1){
      break;
    }
    if(x[i]>y[1][j]){
      vis[i]=1;
      j++;
    }
  }
  if(j!=f1){
    cout<<ans<<endl;
    return 0;
  }
  j=0;
  int cur = 0;
  for(int i=0;i<m;i++){
    if(j==f){
      break;
    }
    if(vis[i]){
      continue;
    }
    if(x[i]>=y[0][j]){
      vis[i]=1;
      cur+=(x[i]-y[0][j]);
      j++;
    }
  }
  if(j!=f){
    cout<<ans<<endl;
    return 0;
  }
  for(int i=0;i<m;i++){
    if(vis[i]==0)
    cur+=x[i];
  }
  ans=max(ans,cur);
  cout<<ans<<endl;
}