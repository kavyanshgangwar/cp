#include <bits/stdc++.h>
using namespace std;
int m;
int a[10];

// this is the function to check condition
bool f(int z){
  return a[z]<=m; // a[z]<m or a[z]<=m
}

// this is the main function
int main(){
  int n;
  cin>>n;
  cin>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int i = 0;
  int k = n;
  while(k){
    while(k+i<n && f(k+i)){
      i+=k;
    }
    k/=2;
  }
  if(a[i]==m){
    cout<<i<<endl;
  }
  
}