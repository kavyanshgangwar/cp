#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int dp[n]={0};
  for(int i=0;i<n;i++){
    if(i==0){
      dp[i]=a[i];
    }else if(i==1){
      dp[i] = min(dp[i-1]+a[i],a[i]);
    }else if(i==2){
      dp[i] = min(dp[i-1]+a[i],min(dp[i-2]+a[i],a[i]));
    }else{
      dp[i] = min(dp[i-1]+a[i],min(dp[i-2]+a[i],dp[i-3]+a[i]));
    }
  }
  int ans=INT32_MAX;
  for(int i=n-1;i>=n-3 && i>=0;i--){
    ans=min(ans,dp[i]);
  }
  cout<<ans<<endl;
}