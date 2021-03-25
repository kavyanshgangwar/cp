#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x[n];
  int s=1000000;
  bool vis[1000010];
  memset(vis,0,sizeof(vis));
  vector<int> y;
  for(int i=0;i<n;i++){
    cin>>x[i];
    vis[x[i]]=true;
  }
  // cout<<"yes\n";
  int cnt=0;
  for(int i=0;i<n;i++){
    if(vis[x[i]]){
      if(vis[s+1-x[i]]){
        cnt++;
      }else{
        y.push_back(s+1-x[i]);
        vis[s+1-x[i]]=true;
      }
    }
  }
  cnt/=2;
  int i=1;
    while(cnt--){
      while(vis[i]||vis[s-i+1]){
        i++;
      }
      y.push_back(i);
      y.push_back(s+1-i);
      vis[i]=true;
      vis[s+1-i]=true;
    }
  
  cout<<y.size()<<endl;
  for(auto z:y){
    cout<<z<<" ";
  }
  cout<<endl;
}