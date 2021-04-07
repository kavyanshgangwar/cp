#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int dp[5010]={0};
  int ans=0;
  for(int i=0;i<n;i++){
    dp[i]=1;
    for(int j=0;j<i;j++){
      if((a[i]<0 && a[j]>0) || (a[i]>0 && a[j]<0) ){
        if(abs(a[i])>abs(a[j])){
          dp[i] = max(dp[i],dp[j]+1);
        }
      }
    }
    ans = max(ans,dp[i]);
  }
  cout<<ans<<endl;
}