#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a;
  set<int> s;
  for(int i=0;i<n;i++){
    cin>>a;
    s.insert(a);
  }
  for(auto x:s){
    cout<<x<<" ";
  }
  cout<<endl;
}