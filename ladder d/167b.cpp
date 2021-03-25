#include <bits/stdc++.h>
using namespace std;
double p[210];
int a[210]={0};
double dp[210][210][210];
double f(int i,int l,int k){
  if(i<l){
    return 0;
  }
  if(k<0){
    return 0;
  }
  if(i==0){
    if(k<0){
      return 0;
    }
    if(l>0){
      return 0;
    }
    return 1;
  }
  
  if(dp[i][l][k]<0){
    dp[i][l][k] = f(i-1,l,k)*(1-p[i]) + f(i-1,l-1,min(k+a[i],201))*p[i]; 
    
  }
  return dp[i][l][k];
}
int main(){
  for(int i=0;i<210;i++){
    for(int j=0;j<210;j++){
      for(int k=0;k<210;k++){
        dp[i][j][k]=-1;
      }
    }
  }
  int n;
  cin>>n;
  int l,k;
  cin>>l>>k;
  pair<int,int> z[n+1];
  for(int i=1;i<=n;i++){
    cin>>z[i].second;
  }
  for(int i=1;i<=n;i++){
    cin>>z[i].first;
  }
  sort(z+1,z+n+1);
  for(int i=1;i<=n;i++){
    p[i] = z[i].second;
    p[i]= p[i]/100.00;
    a[i] = z[i].first;
  }
  double ans = f(n,l,min(k,201));
  printf("%.15f\n",ans);
}