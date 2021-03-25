#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  int v[n];
  for(int i=0;i<n;i++){
    cin>>v[i];
    v[i]--;
  }
  int m[n]={0};
  for(int k=n-1;k>=0;k--){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a[i][j]=min(a[i][j],a[i][v[k]]+a[v[k]][j]);
      }
    }
    for(int i=n-1;i>=k;i--){
      for(int j=i;j>=k;j--){
        m[k]+=a[v[i]][v[j]];
        m[k]+=a[v[j]][v[i]];
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<m[i]<<" ";
  }
  cout<<endl;
}