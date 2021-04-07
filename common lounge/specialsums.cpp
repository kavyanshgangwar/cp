#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n+1];
  int b[n+1];
  int mx = INT32_MIN;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    mx = max(mx,a[i]);
  }
  int p[n+1]={0};
  for(int i=1;i<=n;i++){
    cin>>b[i];
    p[i]=b[i]+p[i-1];
  }
  // i<j
  int prev = a[1]-p[1];
  for(int i=2;i<=n;i++){
    mx = max(mx,a[i]+p[i-1]+prev);
    prev = max(prev,a[i]-p[i]);
  }
  //i>j
  prev = a[n]-p[n];
  for(int i=n-1;i>0;i--){
    mx = max(mx,a[i]+p[i-1]+prev+p[n]);
    prev = max(prev,a[i]-p[i]);
  }
  cout<<mx<<endl;
}