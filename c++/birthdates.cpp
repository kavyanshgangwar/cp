#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,pair<int,int> > > v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].second.first>>v[i].first>>v[i].second.second;
  }
  sort(v.begin(),v.end());
  for(auto x:v){
    cout<<x.second.first<<" "<<x.first<<" "<<x.second.second<<endl;
  }
}