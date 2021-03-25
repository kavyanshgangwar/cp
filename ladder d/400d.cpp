#include <bits/stdc++.h>
using namespace std;
#define viii vector<pair<pair<int,int>,int > >
#define vi vector<int> 
#define vii vector<pair<int,int> >
#define f first
#define s second 
const int INF = 1000000;
class UFDS{
  public:
  vi parent;
  UFDS(int n){
    parent.assign(n+1,0);
    for(int i=1;i<=n;i++){
      parent[i]=i;
    }
  }
  int findParent(int i){
    if(parent[i]!=i){
      parent[i] = findParent(parent[i]);
    }
    return parent[i];
  }
  void u(int x,int y){
    x = findParent(x);
    y = findParent(y);
    if(x!=y){
      if(x>y){
        parent[y]=x;
      }else{
        parent[x]=y;
      }
    }
  }
};
int main(){
  ios_base::sync_with_stdio(0);
  int n,m,k;
  cin>>n>>m>>k;
  int c[k+1]={0};
  for(int i=1;i<=k;i++){
    cin>>c[i];
    c[i]+=c[i-1];
  }
  int u,v,x;
  viii edge;
  vi adj[n+1];
  for(int i=0;i<m;i++){
    cin>>u>>v>>x;
    if(x==0){
      adj[u].push_back(v);
    }
    edge.push_back({{u,v},x});
  }
  
  UFDS ufds = UFDS(n+1);
  for(int i=1;i<=n;i++){
    for(int j=0;j<adj[i].size();j++){
      ufds.u(i,adj[i][j]);
    }
  }

  bool ans=true;
  for(int i=1;i<=k;i++){
    int cur = ufds.findParent(c[i]);
    for(int j=c[i-1]+1;j<=c[i];j++){
      if(ufds.findParent(j)!=cur){
        ans=false;
      }
    }
  }
  if(!ans){
    cout<<"No\n";
    return 0;
  }
  cout<<"Yes\n";
  int a[k+1][k+1];
  for(int i=0;i<k+1;i++){
    for(int j=0;j<k+1;j++){
      a[i][j]=INF;
    }
    a[i][i]=0;
  }
  int q[100010];
  for(int i=1;i<=k;i++){
    for(int j=c[i-1]+1;j<=c[i];j++)
    q[j]=i;
  }
  for(auto x:edge){
    int i,j,w;
    i=q[x.f.f];
    j = q[x.f.s];
    w = x.s;
    a[i][j] = min(a[i][j],w); 
    a[j][i] = a[i][j];
  }
  // for(int i=1;i<=k;i++){
  //   for(int j=1;j<=k;j++){
  //     cout<<a[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  for(int z=1;z<=k;z++){
    for(int i=1;i<=k;i++){
      for(int j=1;j<=k;j++){
        a[i][j]=min(a[i][j],a[i][z]+a[z][j]);
      }
    }
  }
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      if(a[i][j]==INF){
        cout<<-1<<" ";
      }else{
        cout<<a[i][j]<<" ";
      }
    }
    cout<<endl;
  }
}