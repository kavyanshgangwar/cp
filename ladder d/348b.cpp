#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010];
int d[100010];
vector<int> v[100010];
ll ans=0;
ll gcd(ll a,ll b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  if(a==0){
    return b;
  }
  if(b==0){
    return a;
  }
  return (a*b/gcd(a,b));
}
void f1(int u,int p){
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      f1(v[u][i],u);
    }
  }
  int lm = 1;
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      lm = lcm(d[v[u][i]],lm);
    }
  }
  // if(u==2){
  //   cout<<"lm: "<<lm<<endl;
  // }
  if(v[u].size()!=1)
  d[u] = (v[u].size()-1)*lm;
  else
  d[u] = 1;
}
void f(int u,int p){
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      f(v[u][i],u);
    }
  }
  if(v[u].size()==1)return;
  ll mn = INT64_MAX;
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p)
    mn = min(a[v[u][i]],mn);
  }
  int t = d[u]/(v[u].size()-1);
  mn = (mn/t)*t;
  for(int i=0;i<v[u].size();i++){
    if(v[u][i]!=p){
      ans+= (a[v[u][i]]-mn);
      a[v[u][i]]=mn;
      a[u]+=mn;
    }
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]){
      d[i]=1;
    }
  }
  int x,y;
  
  for(int i=0;i<n-1;i++){
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  f1(1,0);
  // for(int i=0;i<=n;i++){
  //   cout<<d[i]<<" ";
  // }
  // cout<<endl;
  f(1,0);
  cout<<ans<<endl;
}