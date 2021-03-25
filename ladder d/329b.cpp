#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,c;
  cin>>r>>c;
  char a[r][c];
  bool vis[r][c];
  pair<int,int> s,e;
  int dp[r][c];
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>>a[i][j];
      if(a[i][j]=='E'){
        e = {i,j};
      }
      if(a[i][j]=='S'){
        s = {i,j};
      }
      vis[i][j]=false;
      dp[i][j]=INT32_MAX;
    }
  }
  queue<pair<int,pair<int,int> > > q;
  q.push({0,e});
  while(!q.empty()){
    int k = q.front().first;
    pair<int,int> u = q.front().second;
    q.pop();
    int i=u.first;
    int j=u.second;
    if(vis[i][j]){
      continue;
    }
    vis[i][j]=true;
    dp[i][j]=k;
    if(i>0){
      if(a[i-1][j]!='T'){
        if(!vis[i-1][j]){
          q.push({k+1,{i-1,j}});
        }
      }
    }
    if(i<r-1){
      if(a[i+1][j]!='T'){
        if(!vis[i+1][j]){
          q.push({k+1,{i+1,j}});
        }
      }
    }
    if(j>0){
      if(a[i][j-1]!='T'){
        if(!vis[i][j-1]){
          q.push({k+1,{i,j-1}});
        }
      }
    }
    if(j<c-1){
      if(a[i][j+1]!='T'){
        if(!vis[i][j+1]){
          q.push({k+1,{i,j+1}});
        }
      }
    }
  }
  int cnt = 0;
  int z = dp[s.first][s.second];
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(dp[i][j]<=z){
        if(a[i][j]!='S' && a[i][j]!='E' && a[i][j]!='T'){
          cnt+=(int)(a[i][j]-'0');
        }
      }
    }
  }
  cout<<cnt<<endl;
}