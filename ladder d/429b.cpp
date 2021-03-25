#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin>>n>>m;
  int dp[n][m],dp2[n][m],dp3[n][m],dp4[n][m];
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(j==0){
        if(i==0)
        dp[i][j] = a[0][0];
        else
        dp[i][j] = dp[i-1][j]+a[i][j];
      }else{
        if(i==0){
          dp[i][j] = dp[i][j-1] + a[i][j];
        }else{
          dp[i][j]= max(dp[i][j-1],dp[i-1][j])+a[i][j];
        }
      }
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      if(j==m-1){
        if(i==n-1){
          dp2[i][j]=a[i][j];
        }else{
          dp2[i][j]=dp2[i+1][j]+a[i][j];
        }
      }else{
        if(i==n-1){
          dp2[i][j]=dp2[i][j+1]+a[i][j];
        }else{
          dp2[i][j]=max(dp2[i][j+1],dp2[i+1][j])+a[i][j];
        }
      }
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<m;j++){
      if(j==0){
        if(i==n-1){
          dp3[i][j]=a[i][j];
        }else{
          dp3[i][j] = dp3[i+1][j] +a[i][j];
        }
      }else{
        if(i==n-1){
          dp3[i][j] = dp3[i][j-1] + a[i][j];
        }else{
          dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1]) +a[i][j];
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=m-1;j>=0;j--){
      if(j==m-1){
        if(i==0){
          dp4[i][j]=a[i][j];
        }else{
          dp4[i][j] = dp4[i-1][j]+a[i][j];
        }
      }else{
        if(i==0){
          dp4[i][j]=dp4[i][j+1]+a[i][j];
        }else{
          dp4[i][j]=max(dp4[i][j+1],dp4[i-1][j])+a[i][j];
        }
      }
    }
  }
  int ans=0;
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      ans=max(ans,max(dp[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1],dp[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]));
    }
  }
  cout<<ans<<endl;
}