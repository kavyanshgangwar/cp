#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
  int n;
  cin>>n;
  int d;
  cin>>d;
  int a[n+5]={0};
  for(int i=2;i<n;i++){
    cin>>a[i];
  }
  pair<int,int> c[n+1];
  for(int i=1;i<=n;i++){
    cin>>c[i].f>>c[i].s;
  }
  int v[n+1][n+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j){
        int z = abs(c[i].f-c[j].f) + abs(c[i].s - c[j].s);
        v[i][j] = d*z-a[i];
        v[j][i] = d*z-a[j];
      }else{
        v[i][j]=0;
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
      }
    }
  }
  cout<<v[1][n]<<endl;
}