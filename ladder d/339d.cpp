#include <bits/stdc++.h>
using namespace std;
void build(int p,int a[],int n,int k,int h){
  if(p>=n){
    return;
  }
  build(p<<1,a,n,k+1,h);
  build((p<<1)+1,a,n,k+1,h);
  if((h%2)==(k%2)){
    a[p]=a[p<<1]^a[(p<<1)+1];
  }else{
    a[p]=a[p<<1]|a[(p<<1)+1];
  }
}
int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  int sz = pow(2,n);
  int a[4*sz];
  for(int i=0;i<sz;i++){
    cin>>a[sz+i];
  }
  // printf("building...");
  build(1,a,sz,0,n);
  // printf("built!");
  // for(int i=1;i<sz*2;i++){
  //   cout<<a[i]<<" ";
  // }
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    a[sz+x-1]=y;
    y=n-1;
    x+=sz;
    x--;
    while(1){
      x = x>>1;
      if(y%2==n%2){
        a[x] = a[x<<1]^a[(x<<1)+1];
      }else{
        a[x] = a[x<<1]|a[(x<<1)+1];
      }
      y--;
      // if(x==0){
      //   cout<<"x is 0\n";
      //   break;
      // }
      // cout<<x<<endl;
      if(x==1){
        break;
      }
    }
    cout<<a[1]<<endl;
  }
}