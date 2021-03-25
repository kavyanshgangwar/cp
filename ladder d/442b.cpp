#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  double cur,p;
  double ans = 0;
  for(int i=n-1;i>=0;i--){
    for(int j=i;j>=0;j--){
      cur =0;
      p = 1;
      for(int k=i;k>=j;k--){
        p*=(1-a[k]);
      }
      for(int k=i;k>=j;k--){
        if(a[k]!=1)
        cur+= (p/(1-a[k])*a[k]);
        else cur = 1;
        ans=max(ans,cur);
      }
    }
  }
  printf("%0.10f\n",ans);
}