#include <bits/stdc++.h>
using namespace std;
int n,c;
vector<int> v;
bool check(int x){
  // for(auto m:v){
  //   cout<<m<<" ";
  // }
  // cout<<endl;
  int j=1;
  int z = c-1;
  int prev = v[0];
  while(z){
    if(j==n){
      // cout<<x<<" ";
      // cout<<z<<endl;
      return false;
    }
    if((v[j]-prev) >= x){
      z--;
      prev = v[j];
    }
    j++;
    
  }
  return true;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n>>c;
    v.assign(n,0);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0;
    int k=v[n-1];
    while(k){
      while(i+k<=v[n-1] && check(i+k)){
        i+=k;
      }
      k/=2;
    }
    cout<<i<<endl;
    v.clear();
  }
}