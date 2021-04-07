#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool comp(pair<int,int> &a,pair<int,int> &b){
  return a.s>b.s;
}
int main(){
  int n;
  cin>>n;
  int b;
  pair<int,int> a[n];
  for(int i=0;i<n;i++){
    cin>>a[i].f>>a[i].s>>b;
    a[i].s+=b;
  }
  sort(a,a+n,comp);
  int ans=0;
  int sm=0;
  for(int i=0;i<n;i++){
    sm+=a[i].f;
    ans = max(ans,sm+a[i].s);
  }
  cout<<ans<<endl;
}