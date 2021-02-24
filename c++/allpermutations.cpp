#include <bits/stdc++.h>
using namespace std;
int main(){
  int n=10;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    v[i]=i;
  }
  int cnt=0;
  do{
    cnt++;
    // for(auto x:v){
    //   cout<<x<<" ";
    // }
    // cout<<endl;
  }while(next_permutation(v.begin(),v.end()));
  cout<<cnt<<endl;
}