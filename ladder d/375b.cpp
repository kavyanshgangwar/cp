#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  int a[n][m];
  char c;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>c;
      if(c=='0'){
        a[i][j]=0;
      }else{
        a[i][j]=1;
      }
      
    }
  }
  for(int i=0;i<n;i++){
    for(int j=1;j<m;j++){
      if(a[i][j]){
        a[i][j]+=a[i][j-1];
      }
    }
  }
  int ans=0;
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<a[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  for(int i=0;i<m;i++){
    int dp[m+1]={0};
    for(int j=0;j<n;j++){
      dp[a[j][i]]++;
    }
    int cnt = 0;
    for(int j=m;j>0;j--){
      cnt += dp[j];
      ans = max(ans,j*cnt);
    }
  }
  cout<<ans<<endl;
}