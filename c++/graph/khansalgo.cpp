#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,e;
  cin>>n>>e;
  int u,b;
  vector<int> deg(n+1,0);
  vector<int> v[n+1];
  for(int i=0;i<e;i++){
    cin>>u>>b;
    v[u].push_back(b);
    deg[b]++;
  }
  queue<int> q;
  for(int i=0;i<n;i++){
    if(!deg[i]){
      q.push(i);
    }
  }
  vector<int> l;
  while(!q.empty()){
    u = q.front();
    q.pop();
    l.push_back(u);
    for(int i=0;i<v[u].size();i++){
      deg[v[u][i]]--;
      if(!deg[v[u][i]]){
        q.push(v[u][i]);
      }
    }
  }
  for(int x:l){
    cout<<x<<" ";
  } 
  cout<<"\n";
}