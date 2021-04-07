#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++){
      cin>>a[i];
    }
    int table[n]={0};
    int next[n] = {0};
    bool sit[401]={0};
    int cnt=0;
    for(int i=0;i<m;i++){
        
      if(!sit[a[i]]){
        for(int j=0;j<n;j++){
          if(table[j]==0){
            table[j]=a[i];
            cnt++;
            sit[a[i]]=true;
            break;
          }
        }
        if(!sit[a[i]]){
          int cur=0;
          for(int j=0;j<n;j++){
            if(next[cur]<next[j]){
              cur = j;
            }
          }
          sit[table[cur]]=false;
          sit[a[i]]=true;
          table[cur] = a[i];
          cnt++;
        }
      }
      int cur = 0;
      while(table[cur]!=a[i]){
        cur++;
      }
      int j=i;
      for( j=i+1;j<n;j++){
        if(a[j]==a[i]){
          break;
        }
      }
      next[cur]=j;
    }
    cout<<cnt<<endl;
  }
}