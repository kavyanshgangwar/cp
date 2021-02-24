#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  list<int> l;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    l.push_back(a);
  }
  for(auto it:l){
    cout<<it<endl;
  }
}