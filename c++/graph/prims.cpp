#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  int u,v,w;
  priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
  
  vector<pair<int,int> > e[n];
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    if(u==0){
      pq.push({w,v});
    }
    e[u].push_back({w,v});
    e[v].push_back({w,u});
  }
  bool vis[n]={0};
  int sm=0;
  vis[0]=true;
  while(!pq.empty()){
    u = pq.top().second;
    w = pq.top().first;
    pq.pop();
    if(!vis[u]){
      for(int i=0;i<e[u].size();i++){
        pq.push(e[u][i]);
      }
      // cout<<w<<" ";
      vis[u]=true;
      sm+=w;
    }
  }
cout<<sm<<endl;
}