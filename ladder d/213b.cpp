#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int fact[105];
int a[10];
int dp[101][10];
int p(int a,int b){
  if(b==0){
    return 1;
  }
  if(b==1){
    return a%mod;
  }
  if(b%2==0){
    int k = p(a,b/2);
    return (((k%mod)*(k%mod))%mod);
  }else{
    int k = p(a,b/2);
    return (((k%mod)*(k%mod)*(a%mod))%mod);
  }
}
int modInverse(int k){
  return p(k,mod-2);
}
int c(int n,int r,int k){
  return (fact[n]%mod * modInverse(fact[r])%mod * modInverse(fact[k])%mod)%mod;
}
int f(int len,int i){
  if(i==9){
    if(len>=a[9]){
      return 1;
    }else{
      return 0;
    }
  }
  if(dp[len][i]!=-1){
    return dp[len][i];
  }
  if(i==0){
    
    int ans =0 ;
    for(int j=a[0];j<=len;j++){
      ans = (ans%mod + (f(len-j,1)%mod*c(len-1,j,len-j-1)%mod)%mod)%mod;
    }
    dp[len][i] = ans;
    
  }else{
    int ans=0;
    for(int j=a[i];j<=len;j++){
      ans = (ans%mod + (f(len-j,i+1)%mod*c(len,j,len-j)%mod)%mod)%mod;
    }
    dp[len][i] = ans;
  }
  return dp[len][i];
}
int main(){
  int n;
  cin>>n;
  
  int sm=0;
  for(int i=0;i<10;i++){
    cin>>a[i];
    sm+=a[i];
  }
  
  fact[0]=1;
  for(int i=1;i<=101;i++){
    fact[i] = (fact[i-1]%mod * i%mod)%mod;
  }
  int ans=0;
  memset(dp,-1,sizeof(dp));
  for(int i=sm;i<=n;i++){
    ans= (ans%mod + f(i,0)%mod)%mod;
  }
  cout<<ans%mod<<endl;
}