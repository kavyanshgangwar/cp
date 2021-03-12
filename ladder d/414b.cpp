#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2010][2010];
int n;
const int mod = 1000000007;
int f(int i,int k){
  if(k==0){
    return 1;
  }else{
    if(dp[i][k]==0){
      for(int z=1;z*i<=n;z++){
        dp[i][k] = (dp[i][k]+f(i*z,k-1))%mod;
      }
    }
  }
  return dp[i][k];
}
signed main(){
  int k;
  cin>>n>>k;
  memset(dp,0,sizeof(dp));
  int ans=0;
  for(int i=1;i<=n;i++){
    ans = (ans + f(i,k-1))%mod;
  }
  cout<<ans<<endl;
}