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
    int a[n],b[n];
    pair<int,int> c[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)c[i]={a[i]+b[i],i};
    sort(c,c+n);
    int ans=0;
    int x=0,y=0;
    while(x+y<n){
      x++;
      ans+=a[c[n-x-y].s];
      if(x+y==n)break;
      y++;
      ans-=b[c[n-y-x].s];
      
    }
    // cout<<ans<<endl;
    if(ans==0){
      cout<<"Tie\n";
    }else if(ans>0){
      cout<<"First\n";
    }else{
      cout<<"Second\n";
    }
  }
}