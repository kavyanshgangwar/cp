#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> v;
  int a;
  while(cin>>a){
    v.push_back(a);
  }
  int n = v.size();
  vector<int> lis;
  vector<int> pos;
  vector<int> b(n,-1);
  for(int i=0;i<n;i++){
    auto it = lower_bound(lis.begin(),lis.end(),v[i]);
    if(it==lis.end()){
      lis.push_back(v[i]);
      pos.push_back(i);
      if(pos.size()>1){
        b[i]=pos[pos.size()-2];
      }
    }else{
      lis[it-lis.begin()]=v[i];
      pos[it-lis.begin()]=i;
      if(it-lis.begin())
        b[i]=pos[it-lis.begin()-1];
    }
  }
  int mx = lis.size();
  cout<<mx<<endl;
  cout<<"-\n";
  int cur = pos[pos.size()-1];
  stack<int> s;
  while(1){
    s.push(v[cur]);
    cur = b[cur];
    if(cur==-1){
      break;
    }
  }
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
}