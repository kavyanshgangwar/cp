#include <bits/stdc++.h>
using namespace std;
int main(){
  // scale down the number everytime...this will lead to same case
  int w;
  cin>>w;
  int ans=1;
  vector<int> v;
  while(w){
    if(w%3==1){
      w--;
      v.push_back(ans);
    }else if(w%3==2){
      w++;
      v.push_back(-ans);
    }
    ans*=3;
    w/=3;
  }
  sort(v.begin(),v.end());
  for(auto x:v)cout<<x<<" ";
  cout<<endl;
}