#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
signed main(){
  int n;
  cin>>n;
  int p[n];
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  int dp[n][2];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=1;i<n;i++){
    dp[i][1] = (dp[i-1][0] + 1)%mod;
    dp[i][0] = (((2*dp[i][1])%mod) + 1 - dp[p[i]-1][1] + mod)%mod;
  }
  cout<<dp[n-1][0]+1<<endl;
}