#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,x,y;
  cin>>n>>x>>y;
  int a[n],b[n];
  int sa=0,sb=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sa+=a[i];
  }
  int diff[n];
  for(int i=0;i<n;i++){
    cin>>b[i];
    diff[i]=a[i]-b[i];
    sb+=b[i];
  }
  sort(diff,diff+n);
  int a1=0;int b1=0;
  while(n-a1>y){
    a1++;
    sb+=diff[n-a1];
  }
  while(a1<x){
    a1++;
    if(diff[n-a1]>0){
      sb+=diff[n-a1];
    }else{
      break;
    }
  }
  while(n-b1>x){
    sa-=diff[b1];
    b1++;
  }
  while(b1<y){
    if(diff[b1]<0)
    {sa-=diff[b1];
    b1++;}else{
      break;
    }
  }
  cout<<max(sa,sb)<<endl;
}