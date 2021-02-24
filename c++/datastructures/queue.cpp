#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  queue<int> q;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    q.push(a);
  }
  for(int i=0;i<n;i++){
    cout<<q.front()<<endl;
    q.pop();
  }
}