#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  if(n==1){
    cout<<0<<endl;
    return 0;
  }else if(n==2){
    cout<<min(a[0],a[1])<<endl;
    return 0;
  }
  int dp[n]={0};
  dp[1]=a[1];
  dp[2]=a[2]+a[1];
  for(int i=3;i<n;i++){
    dp[i] = min(dp[i-1],dp[i-2])+a[i];
    // cout<<dp[i]<<" ";
  }
  int mx = dp[n-1];
  dp[0]=a[0];
  dp[1]=a[1]+a[0];
  for(int i=2;i<n;i++){
    dp[i] = min(dp[i-1],dp[i-2])+a[i];
  }
  mx = min(mx,min(dp[n-1],dp[n-2]));
  cout<<mx<<endl;
}