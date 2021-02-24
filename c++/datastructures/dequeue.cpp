#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  deque<int> q;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    q.push_back(a);
  }
  for(int i=0;i<n;i++){
    cin>>a;
    q.push_front(a);
  }
  while(!q.empty()){
    cout<<q.front()<<" "<<q.back()<<endl;
    q.pop_front();
    q.pop_back();
  }
}