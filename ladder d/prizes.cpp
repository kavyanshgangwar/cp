#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;
  cin>>n;
  int p[n];
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int sm=0;
  int ansa=0,ansb=0,ansc=0,ansd=0,anse=0;
  for(int i=0;i<n;i++){
    sm+=p[i];
    while(sm>=a){
      // cout<<sm<<endl;
      while(sm>=e){
        anse += (sm/e);
        sm=sm%e;
        
      }
      while(sm>=d){
        ansd+=(sm/d);
        sm=sm%d;
      }
      while(sm>=c){
        ansc+=(sm/c);
        sm=sm%c;
      }
      while(sm>=b){
        ansb+=(sm/b);
        sm=sm%b;
      }
      while(sm>=a){
        ansa+=(sm/a);
        sm=sm%a;
      }
    }
  }
  cout<<ansa<<" "<<ansb<<" "<<ansc<<" "<<ansd<<" "<<anse<<endl;
  cout<<sm<<endl;
}