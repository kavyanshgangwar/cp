#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int> > g[n];
  int a,b,w;
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    g[a].push_back({b,w});
  }
  int s;
  cin>>s;
  priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
  pq.push({0,s});
  vector<int> dist(n,INF);
  while(!pq.empty()){
    a = pq.top().first;
    b = pq.top().second;
    pq.pop();
    if(dist[b]<a){
      continue;
    }
    dist[b]=a;
    for(int i=0;i<g[b].size();i++){
      if(dist[g[b][i].first]>a+g[b][i].second){
        dist[g[b][i].first]=a+g[b][i].second;
        pq.push({a+g[b][i].second,g[b][i].first});
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
  }
  cout<<endl;
}