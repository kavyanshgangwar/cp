#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  queue<int> q1,q2;
  for(int i=n-1;i>=0;i--)q1.push(a[i]);
  int q;
  int cur = 0;
  for(int i=0;i<m;i++){
    cin>>q;
    q--;
    while(cur<q){
      cur++;
      if(q1.empty()){
        q2.push(q2.front()/2);
        q2.pop();
      }else if(q2.empty()){
        q2.push(q1.front()/2);
        q1.pop();
      }else{
        if(q2.front()>q1.front()){
          q2.push(q2.front()/2);
          q2.pop();
        }else{
          q2.push(q1.front()/2);
          q1.pop();
        }
      }
    }
    int ans = 0;
    cur++;
    if(q1.empty()){
      ans=q2.front();
      q2.push(q2.front()/2);
      q2.pop();
    }else if(q2.empty()){
      ans = q1.front();
      q2.push(q1.front()/2);
      q1.pop();
    }else{
      if(q2.front()>q1.front()){
        ans=q2.front();
        q2.push(q2.front()/2);
        q2.pop();
      }else{
        ans = q1.front();
        q2.push(q1.front()/2);
        q1.pop();
      }
    }
    cout<<ans<<endl;
  }
}