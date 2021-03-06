#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> v[10];
void dfs(int u){
  printf("%d ",u);
  if(!vis[u]){
    vis[u]=true;
    for(int i=0;i<v[u].size();i++){
      if(!vis[v[u][i]]){
        dfs(v[u][i]);
      }
    }
  }
}
int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  
  int a,b;
  vis.assign(n,0);
  for(int i=0;i<m;i++){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0);
}