#include <bits/stdc++.h>
using namespace std;
int main(){
  int x1,y1,z1,x,y,z;
  cin>>x>>y>>z;
  cin>>x1>>y1>>z1;
  int a[7];
  for(int i=1;i<=6;i++){
    cin>>a[i];
  }
  int sm=0;
  if(y>y1){
    sm+=a[2];
  }
  if(y<0){
    sm+=a[1];
  }
  if(x>x1){
    sm+=a[6];
  }
  if(x<0){
    sm+=a[5];
  }
  if(z>z1){
    sm+=a[4];
  }
  if(z<0){
    sm+=a[3];
  }
  cout<<sm<<endl;
}