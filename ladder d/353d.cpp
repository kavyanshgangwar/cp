#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n = s.size();
  int cnt = 0;
  int dp[n];
  for(int i=0;i<n;i++){
    if(s[i]=='F'){
      dp[cnt]=i;
      cnt++;
    }
  }
  int t[cnt+1]={0};
  for(int i=0;i<cnt;i++){
    t[i] = dp[i]-i;
    if(i>0){
      if(t[i]<=t[i-1]){
        if(t[i]!=0)
        t[i]=t[i-1]+1;
      }
    }
  }
  if(cnt)
  cout<<t[cnt-1]<<endl;
  else cout<<0<<endl;
}