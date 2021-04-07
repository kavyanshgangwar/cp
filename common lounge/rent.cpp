#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    pair<int,pair<int,int> > p[n];
    for(int i=0;i<n;i++){
      cin>>p[i].s.f>>p[i].f>>p[i].s.s;
      p[i].f+=p[i].s.f;
    }
    sort(p,p+n);
    int ans=0;
    int dp[n] = {0};
    for(int i=n-1;i>=0;i--){
      dp[i] = p[i].s.s;
      for(int j=n-1;j>i;j--){
        if(p[j].s.f>=p[i].f)
        dp[i] = max(dp[i],dp[j]+p[i].s.s);
      }
      ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
  }
}