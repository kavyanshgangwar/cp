#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n = s.size();
    int dp[2][n];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--){
      for(int j=0;j<n;j++){
        if(i>=j){
          continue;
        }
        if(s[i]!=s[j]){
          dp[i%2][j] = 1 + min(dp[(i+1)%2][j],dp[i%2][j-1]);
        }else{
          dp[i%2][j] = dp[(i+1)%2][j-1];
        }
      }
    }
    cout<<dp[0][n-1]<<endl;
  }
}