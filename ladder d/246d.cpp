#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  int c[n+1];
  set<int> s[100010];
  for(int i=1;i<=n;i++){
    cin>>c[i];
  }
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(c[b]!=c[a]){
    s[c[a]].insert(c[b]);
    s[c[b]].insert(c[a]);
    }
  }
  int ans = c[1];
  for(int i=1;i<=n;i++){
    if(s[c[i]].size()>s[ans].size()){
      ans=c[i];
    }
    if(s[c[i]].size()==s[ans].size()){
      if(c[i]<ans){
        ans=c[i];
      }
    }
  }
  cout<<ans<<endl;
}