#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
using namespace std;
signed main(){
  int n;
  cin>>n;
  int m,u,v,w,z,t;
  cin>>m;
  vector<pair<int,int> > g[n+1];
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  vector<int> k[n+1];
  for(int i=1;i<=n;i++){
    cin>>z;
    while(z--){
      cin>>t;
      k[i].push_back(t);
    }
  }
  priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > >pq;
  int dist[n+1];
  for(int i=0;i<n+1;i++){
    dist[i]=INT32_MAX;
  }
  bool vis[n+1];
  memset(vis,0,sizeof(vis));
  pq.push({0,1});
  while(!pq.empty()){
    u = pq.top().s;
    w = pq.top().f;
    pq.pop();
    if(vis[u])continue;
    vis[u]=true;
    dist[u]=w;
    if(u==n)break;
    for(int i=0;i<k[u].size();i++){
      if(k[u][i]==w){
        w++;
      }
    }
    dist[u]=w;
    for(int i=0;i<g[u].size();i++){
      v = g[u][i].f;
      z = g[u][i].s;
      if(!vis[v])
      if(dist[v]>w+z){
        pq.push({w+z,v});
      }
    }
  }
  if(dist[n]!=INT32_MAX)
  cout<<dist[n]<<endl;
  else
  cout<<-1<<endl;
}