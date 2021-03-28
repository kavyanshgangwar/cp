#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int mxdepth = 0;
  int depth_cur = 0;
  int mxsym = 0;
  int sym_cur = 0;
  int prev = -1;
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[i]==1){
      ans++;
    }
    if(a[i]==2){
      ans--;
    }
    if(ans==0){
      if(mxsym<(i-prev)){
        mxsym = i-prev;
        sym_cur = prev+1;
        
      }
      prev = i;
    }
    if(ans>mxdepth){
      mxdepth=ans;
      depth_cur = i+1;
    }
  }
  cout<<mxdepth<<" "<<depth_cur<<" "<<mxsym<<" "<<sym_cur+1<<endl;
}