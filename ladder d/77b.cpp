#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int t;
  cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    int k = a*b;
    double area;
    if(a<4*b){
      area = (double)(a*a);
      area /= 8.0; 
    }else{
      area = (double)(k-2*b*b);
    }
    area += k;
    double total = k*2;
    if(b!=0 && a!=0){
      printf("%.9f\n",area/total);

    }else{
      if(b==0)
      printf("%.9f\n",1.0);
      else
      printf("%.9f\n",0.5);
    }
  }
}