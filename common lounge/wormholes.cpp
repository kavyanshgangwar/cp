#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
  int n;
  cin>>n;
  int x,y;
  cin>>x>>y;
  pair<int,int> a[n];
  for(int i=0;i<n;i++){
    cin>>a[i].f>>a[i].s;
  }
  vector<int> v(x),w(y);
  for(int i=0;i<x;i++){
    cin>>v[i];
  }
  for(int i=0;i<y;i++){
    cin>>w[i];
  }
  sort(v.begin(),v.end());
  sort(w.begin(),w.end());
  int ans=INT32_MAX;
  for(int i=0;i<n;i++){
    auto it = upper_bound(v.begin(),v.end(),a[i].f);
    if(it==v.begin())continue;
    it--;
    int st = *it;
    it = lower_bound(w.begin(),w.end(),a[i].s);
    if(it==w.end())continue;
    int et = *it;
    ans = min(ans,et-st+1);
  }
  cout<<ans<<endl;
}