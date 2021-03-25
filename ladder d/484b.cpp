#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[2000010]={0};
  set<int> s;
  int k;
  for(int i=0;i<n;i++){
    cin>>k;
    s.insert(k);
  }
  vector<int> b;
  for(auto x:s){
    b.push_back(x);
  }
  n = b.size();
  int cur = b[0];
  for(int i=1;i<n;i++){
    while(cur<=b[i]){
      a[cur]=b[i-1];
      cur++;
    }
  }
  while(cur<=2000000){
    a[cur]=b[n-1];
    cur++;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=b[i]<<1;j<b[i]+b[n-1];j+=b[i]){
      ans = max(ans,a[j]%b[i]);
    }
  }
  cout<<ans<<endl;
}