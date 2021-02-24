#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  set<int> s;
  int a;

  for(int i=0;i<n;i++){
    cin>>a;
    s.insert(a);
  }

  for(auto x:s){
    cout<<x<<endl;
  }
}