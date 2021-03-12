#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int x,int n,int m){
  int res = 0;
  x--;
  for(int i=1;i<=n;i++){
    res += min(m,x/i);
  }
  return res;
}
signed main(){
  int n,m;
  cin>>n>>m;
  int k;
  cin>>k;
  int l=1,r=n*m+1;
  while(l<r){
    int x = (l+r)>>1;
    if(f(x,n,m)<k){
      l=x+1;
    }else{
      r = x;
    }
  }
  cout<<l-1<<endl;
}