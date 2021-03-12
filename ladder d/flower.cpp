#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int t,k;
  int mod = 1000000007;
  cin>>t>>k;
  int dp[100010]={0};
  dp[1]=1;
  dp[0]=1;
  int sm[100010]={0};
  sm[1]=1;
  for(int i=2;i<k;i++){
    dp[i]=dp[i-1];
    sm[i]=(sm[i-1]%mod+dp[i]%mod)%mod;
  }
  for(int i=k;i<100001;i++){
    dp[i]=(dp[i-1]%mod+dp[i-k]%mod)%mod;
    sm[i]=(sm[i-1]%mod+dp[i]%mod)%mod;
  }
  // cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<"\n";
  while(t--){
    int a,b;
    cin>>a>>b;
    cout<<(sm[b]-sm[a-1]+mod)%mod<<endl;
  }
}