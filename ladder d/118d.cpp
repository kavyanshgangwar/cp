#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[110][110][2];
const int mod = 100000000;
int f(int n1,int n2,int k1,int k2,int c){
  if(n1==0){
    if(c==0){
      return 0;
    }else{
      if(k2>=n2){
        if(n2>0){
          return 1;
        }else{
          return 0;
        }
      }
    }
  }
  if(n2==0){
    if(c==0){
      if(k1>=n1){
        if(n1>0){
          return 1;
        }else{
          return 0;
        }
      }
    }else{
      return 0;
    }
  }
  if(dp[n1][n2][c]==-1){
    dp[n1][n2][c]=0;
    if(c==0){
      for(int i=1;i<=k1;i++){
        if(n1-i>=0)
        dp[n1][n2][c] =(dp[n1][n2][c]+ f(n1-i,n2,k1,k2,1))%mod; 
      }
    }else{
      for(int i=1;i<=k2;i++){
        if(n2-i>=0){
          dp[n1][n2][c] =(dp[n1][n2][c]+ f(n1,n2-i,k1,k2,0))%mod;
        }
      }
    }
  }
  return dp[n1][n2][c];
}
signed main(){
  int n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;
  memset(dp,-1,sizeof(dp));
  cout<<(f(n1,n2,k1,k2,0)+f(n1,n2,k1,k2,1))%mod<<endl;
}