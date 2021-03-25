#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int ans=0;
  if(n==1||m==1){
    ans = max(n,m);
  }else if(n==2||m==2){
    n = max(n,m);
    ans = (n/4)*4;
    if(n%4==1){
      ans+=2;
    }else if(n%4==2 || n%4==3){
      ans+=4;
    }
  }else{
     n *= m;
     ans = n/2 + n%2;
  }
  cout<<ans<<endl;
}