#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int pow(int a,int m){
  if(m==0)return 1;
  if(m%2){
    int k = pow(a,m/2);
    return ((a%mod * (k%mod * k%mod)%mod)%mod);
  }else{
    int k = pow(a,m/2);
    return ((k%mod * k%mod)%mod);
  }
}
int inv(int a){
  return pow(a,mod-2);
}
int fac[200010];
signed main(){
  int t;
  cin>>t;
  fac[0]=1;
  for(int i=1;i<200010;i++){
    fac[i]=(i*fac[i-1])%mod;
  }
  // for(int i=0;i<20;i++){
  //   cout<<fac[i]<<" ";
  // }
  // cout<<endl;
  int c=0;
  while(c<t){
    c++;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x2-=x1;
    y2-=y1;
    int h = x2;
    int v = y2;
    int p = min(x2,y2);
    int ans=0;
    for(int i=0;i<=p;i++){
      int cur = fac[h+v-i]%mod;
      cur = (cur%mod * inv(fac[h-i])%mod)%mod;
      cur = (cur%mod * inv(fac[v-i])%mod)%mod;
      cur = (cur%mod * inv(fac[i])%mod)%mod;
      ans = (ans%mod + cur%mod)%mod;
    }
    cout<<"Case "<<c<<": "<<ans<<endl;

  }
}