#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
  int n;
  cin>>n;
  int a[n];
  pair<int,int> p[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    p[i].first = a[i];
    p[i].second = i;
  }
  sort(p,p+n);
  // for(int i=0;i<n;i++){
  //   cout<<p[i].f<<" : "<<p[i].s<<endl;
  // }
  int cur = -1;
  int v[n]={0};
  for(int i=0;i<n;i++){
    int j=i;
    while(p[j].f==p[i].f){
      
        v[p[j].s] = cur-p[j].s-1; 
    
      j++;
    }
    j--;
    cur = max(cur,p[j].s);
    i=j;
  }
  for(int i=0;i<n;i++){
    if(v[i]<0){
      cout<<-1<<" ";
    }else
    cout<<v[i]<<" ";
  }
  cout<<endl;
}