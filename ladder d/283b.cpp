#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200010][2];
short vis[200010][2];
int a[200010];
int n;
int f(int x,int z){
  if(x>n ||x<=0){
    return 0;
  }else{
    if(dp[x][z]!=0){
      return dp[x][z];
    }
    if(vis[x][z]){
      return -1;
    }
    vis[x][z]=1;
    int y = 0;
    y += a[x];
    int k = 0;
    if(z==0){
      // cout<<x<<" "<<z<<endl;
      k = f(x-a[x],1);
    }else{
      // cout<<x<<" "<<z<<endl;
      k = f(x+a[x],0);
    }
    if(k==-1){
      dp[x][z]=-1;
      return -1;
    }
    y += k;
    dp[x][z]=y;
    return y;
  }
}
signed main(){
  cin>>n;
  
  for(int i=2;i<=n;i++){
    cin>>a[i];
  }
  memset(dp,0,sizeof(dp));
  memset(vis,0,sizeof(vis));
  // cout<<f(4,0)<<endl;
  for(int i=1;i<n;i++){
    int y = f(i+1,0);
    if(y==-1){
      cout<<-1<<endl;
    }else{
      cout<<y+i<<endl;
    }
  }
}