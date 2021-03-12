#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<pair<int,int> > v[n];
  int a,b,w;
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    v[a].push_back({b,w});
  }
  vector<int> dist(n,INF);
  dist[0]=0;
  for(int i=0;i<n-1;i++){
    for(int u=0;u<n;u++){
      for(int j=0;j<v[u].size();j++){
        dist[v[u][j].first] = min(dist[v[u][j].first],dist[u]+v[u][j].second);
      }
    }
  }
  bool neg = false;
    for(int u=0;u<n;u++){
        for(int j=0;j<v[u].size();j++){
          if(dist[v[u][j].first] > dist[u]+v[u][j].second){
            neg=true;
            break;
        }
        if(neg){
          break;
        }
      }
    }
  if(neg){
    cout<<"Negative weight cycle!\n";
  }
  for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
  }
  cout<<endl;
}