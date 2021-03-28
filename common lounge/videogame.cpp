#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,h;
  cin>>n>>h;
  int cur = 0;
  bool hasBox = false;
  int pos = 0;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>cur;
  while(cur){
    if(cur==1){
      if(pos>0){
        pos--;
      }
    }
    if(cur==2){
      if(pos<n-1){
        pos++;
      }
    }
    if(cur==3){
      if(a[pos]>0){
        if(!hasBox){
          a[pos]--;
          hasBox=true;
        }
      }
    }
    if(cur==4){
      if(a[pos]<h){
        if(hasBox){
          a[pos]++;
          hasBox=false;
        }
      }
    }
    cin>>cur;
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;

}