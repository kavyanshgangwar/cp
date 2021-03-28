#include <bits/stdc++.h>
using namespace std;
int main(){
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  int a;
  map<int,int> m;
  while(n1--){
    cin>>a;
    m[a]++;
  }
  while(n2--){
    cin>>a;
    m[a]++;
  }
  while(n3--){
    cin>>a;
    m[a]++;
  }
  vector<int> v;
  for(auto x:m){
    if(x.second>1){
      v.push_back(x.first);
    }
  }
  cout<<v.size()<<endl;
  for(auto x:v){
    cout<<x<<"\n";
  }
}