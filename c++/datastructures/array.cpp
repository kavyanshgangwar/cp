#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j]=n*i+j+1;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}