#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n];
  int dp[n]={0};
  float k;
  int ans=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    cin>>k;
    dp[i]=1;
    for(int j=0;j<i;j++){
      if(a[i]>=a[j]){
        dp[i]=max(dp[i],dp[j]+1);
      }
      ans=max(ans,dp[i]);
    }
  }
  cout<<n-ans<<endl;
}