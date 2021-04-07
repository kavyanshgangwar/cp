#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,j;
  cin>>n>>j;
  j--;
  int a[n];
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int dp[n]={0};
  dp[j+1]=a[j+1];
  for(int i=j+2;i<n;i++){
    dp[i] = max(dp[i-1],dp[i-2])+a[i];
  }
  int dp1[n]={0};
  dp1[0]=a[0];
  dp1[1]=a[1]+a[0];
  for(int i=2;i<n;i++){
    dp1[i] = max(dp1[i-1],dp1[i-2])+a[i];
  }
  int mx = INT32_MIN;
  for(int i=j;i<n;i++){
    int cur = dp[i];
    if(i>1){
      cur+=max(dp1[i-1],dp1[i-2]);
    }else if(i==1){
      cur+=dp1[i-1];
    }
    mx = max(mx,cur);
  }
  cout<<mx<<endl;
}