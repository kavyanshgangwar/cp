#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int n;
  cin>>n;
  int adj[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      adj[i][j]=INF;
    }
  }
  int m;
  cin>>m;
  int a,b,w;
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    adj[a][b]=w;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        adj[i][j]=min(adj[i][k]+adj[k][j],adj[i][j]);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
}