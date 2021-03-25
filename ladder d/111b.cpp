#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x,y;
  int k[100010]={0};
  int cnt;
  int j;
  for(int i=1;i<=n;i++){
    cin>>x>>y;
    cnt=0;
    for(j=1;j*j<x;j++){
      if(x%j==0){
        if(y==0){
          cnt+=2;
        }else{
          if(k[j]<i-y){
            cnt++;
          }
          if(k[x/j]<i-y){
            cnt++;
          }
        }
        k[j]=i;
        k[x/j]=i;
      }
    }
    if(j*j==x){
      if(y==0){
        cnt++;
      }else{
        if(k[j]<i-y){
          cnt++;
        }
      }
      k[j]=i;
    }
    cout<<cnt<<endl;
  }
}