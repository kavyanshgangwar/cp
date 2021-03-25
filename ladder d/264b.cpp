#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int last[100010];
  for(int i=0;i<100010;i++){
    last[i]=-1;
  }
  int ans[n];
  int temp = 1;
  for(int i=0;i<n;i++){
    ans[i]=1;
    for(int d=2;d*d<=a[i];d++){
      if(a[i]%d==0){
        if(last[d]>=0){
          ans[i] = max(ans[i],ans[last[d]]+1);
        }
        if(last[a[i]/d]>=0){
          ans[i]= max(ans[i],ans[last[a[i]/d]]+1);
        }
        last[d]=i;
        last[a[i]/d]=i;
      }
    }
    last[a[i]]=i;
    temp = max(ans[i],temp);
  }
  // for(int i=0;i<n;i++){
  //   cout<<ans[i]<<" ";
  // }
  // cout<<endl;
  cout<<temp<<endl;
}