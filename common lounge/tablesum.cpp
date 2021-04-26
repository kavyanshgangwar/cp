#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n+1];
  multiset<int> s;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    s.insert(a[i]+i);
  }
  for(int k=0;k<n;k++){
    auto it = s.end();
    it--;
    cout<<(*it + k)<<" ";
    it = s.find(a[n-k]+n-k);
    s.erase(it);
    s.insert(a[n-k]-k);
  }
  cout<<endl;
}