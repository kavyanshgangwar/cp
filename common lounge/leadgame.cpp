#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n+1]={0};
  int b[n+1]={0};
  int mx = 0;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    a[i]+=a[i-1];
    b[i]+=b[i-1];
    if(abs(mx)<abs(a[i]-b[i])){
      mx = a[i]-b[i];
    }
  }
  if(mx<0){
    cout<<2<<" ";
  }else{
    cout<<1<<" ";
  }
  cout<<abs(mx)<<endl;
}