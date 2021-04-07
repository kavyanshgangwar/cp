#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int T;
  cin>>T;
  for(int c=1;c<=T;c++){
    int n,k,b,t;
    cin>>n>>k>>b>>t;
    int v[n];
    int x[n];
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
      cin>>x[i];
    }
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    for(int i=n-1;i>=0;i--){
      if(x[i]+v[i]*t >= b){
        k--;
        ans+= cnt;
        if(k==0){
          break;
        }
      }else{
        cnt++;
      }
    }
    cout<<"Case #"<<c<<": ";
    if(k==0){
      cout<<ans<<endl;
    }else{
      cout<<"IMPOSSIBLE\n";
    }
  }

}