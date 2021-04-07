#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
  int t1;
  cin>>t1;
  while(t1--){
  int n,k;
  cin>>n>>k;
  map<int,vector<pair<int,int>> > a;
  int x,y,z;
  for(int i=0;i<n;i++){
    cin>>x>>y>>z;
    a[z].push_back({y,x});
  }
  int cnt=0;
  int t=0;
  for(auto x=a.begin();x!=a.end();x++){
    t=0;
    sort((x->second).begin(),(x->second).end());
    for(int i=0;i<(x->second).size();i++){
      if((x->second)[i].s>=t){
        cnt++;
        t = (x->second)[i].f;
      }
    }
  }
  cout<<cnt<<endl;
}}