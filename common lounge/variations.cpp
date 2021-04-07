#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int k;
  cin>>k;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int ans=0;
  int j=0;
  for(int i=0;i<n;i++){
    if(j<n){
      while(abs(a[i]-a[j])<k){
        j++;
        if(j==n){
          break;
        }
      }
    }
    ans+=(n-j);
  }
  cout<<ans<<endl;
}