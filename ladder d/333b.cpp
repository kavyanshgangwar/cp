#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int row[n+1]={0};
  int col[n+1]={0};
  int x,y;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    row[x]=1;
    col[y]=1;
  }
  int cnt = 0;
  for(int i=2;i<=n/2;i++){
    if(row[i]==0){
      cnt++;
    }
    if(col[i]==0){
      cnt++;
    }
    if(row[n+1-i]==0){
      cnt++;
    }
    if(col[n+1-i]==0){
      cnt++;
    }
  }
  if(n&1){
    if(row[n/2+1]==0 || col[n/2+1]==0)cnt++;
  }
  cout<<cnt<<endl;
}