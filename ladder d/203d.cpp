#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,m;
  cin>>a>>b>>m;
  int vx,vy,vz;
  cin>>vx>>vy>>vz;
  double t = abs(((double)m)/((double)(vy)));
  // cout<<t<<endl;
  double x1 = (double)a;
  x1/=2.0;
  // cout<<x1<<endl;
  x1+= (((double)abs(vx))*t);
  // cout<<x1<<endl;
  double z1 = (((double)abs(vz))*t);
  if(vx<0){
    x1 += a;
  }
  // cout<<x1<<" "<<z1<<endl;
  double x0,z0;
  int k = (int)(x1);
  int k1 = k%(2*a);
  if(k1<a){
    x0 = k1;
    x0 += x1 - k;
  }else{
    x0 = a - k1%a;
    x0 -= (x1 - k);
  }
  k = (int)(z1);
  k1 = k%(2*b);
  if(k1<b){
    z0 = k1;
    z0 += z1 - k;
  }else{
    z0 = b - k1%b;
    z0 -= (z1 - k);
  }
  printf("%.9f %.9f\n",x0,z0);
}