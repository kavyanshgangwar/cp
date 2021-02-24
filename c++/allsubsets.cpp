#include <bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
void subset(int a,int b){
  if(a==n){
    cnt++;
    for(int i=0;i<n;i++){
      if(b&(1<<i)){
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }else{
    subset(a+1,b);
    subset(a+1,b|(1<<a));
  }
}
int main(){
  n=4;
  subset(0,0);
  cout<<cnt<<endl;
}