#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int l,r;
  cin>>l>>r;
  int ans=0;
  for(int i=1;i<=r;i=i<<1){
    if(r-l >= i){
      ans += i;
    }else{
      if((r&i) != (l&i)){
        ans+=i;
      }
    }
  }
  cout<<ans<<endl;
}