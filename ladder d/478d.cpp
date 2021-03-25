#include <bits/stdc++.h>
using namespace std;
int main(){
  int r0,g0;
  cin>>r0>>g0;
  int n = r0+g0;
  n*=2;
  int mod = 1000000007;
  int i=1;
  int dp[6][200010];
  for(i;i*(i+1)<=n;i++){

  }
  for(int r=r0;r>=0;r--){
    dp[i%2][r]=1;
  }
  i--;
  int g;
  int h=i;
  for(i;i>0;i--){
    // cout<<i<<" ";
    for(int r=r0;r>=0;r--){
      // cout<<"r: "<<r<<" g: ";
      dp[i%2][r] =0;
      if(r>=i){
        dp[i%2][r] = dp[(i+1)%2][r-i]%mod;
      }
      g = g0- i*(i-1)/2 + (r0-r);
      if(g>=i){
        dp[i%2][r]=(dp[i%2][r]%mod+dp[(i+1)%2][r]%mod)%mod;
      }
      // cout<<g<<" dp: "<<dp[i][r]<<endl;
    }
  }
  
  cout<<dp[1][r0]%mod<<endl;
}