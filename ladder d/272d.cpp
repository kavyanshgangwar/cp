#include <bits/stdc++.h>
using namespace std;
#define int long long
int m;
int po(int i){
  if(i==0)return 1%m;
  if(i==1){
    return 2%m;
  }else if(i%2==1){
    int k = po(i/2)%m;
    k = (k%m * k%m)%m;
    k = (k*2)%m;
    return k;
  }else{
    int k = po(i/2);
    k = (k%m * k%m)%m;
    return k;
  }
}
signed main(){
  int n;
  cin>>n;
  int a[n];
  int b[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  cin>>m;
  int p[2*n+1]={0};
  int f[2*n+1]={0};
  f[0]=1;
  for(int i=1;i<=2*n;i++){
    int j=i;
    while(j%2==0){
      p[i]++;
      j/=2;
    }
    p[i]+=p[i-1];
    f[i]=((f[i-1]%m)*(j%m))%m;
  }
  // cout<<"e\n";
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++){
    v.push_back({a[i],i});
    v.push_back({b[i],i});
  }
  sort(v.begin(),v.end());
  // cout<<v.size()<<endl;
  int cnt=1;
  int c=0;
  int ans=1;
  for(int i=1;i<2*n;i++){
    // cout<<cnt<<endl;
    if(v[i].first==v[i-1].first){
      cnt++;
      if(v[i]==v[i-1]){
        c++;
      }
      // cout<<cnt<<endl;
    }else{
      ans = (ans%m * (f[cnt]%m) )%m;
      ans = (ans%m * po(p[cnt]-c)%m)%m;
      cnt=1;
      c=0;
    }
  }
  ans = (ans%m * (f[cnt]%m) )%m;
  ans = (ans%m * po(p[cnt]-c)%m)%m;
  cnt=1;
  c=0;
  cout<<ans%m<<endl;
}