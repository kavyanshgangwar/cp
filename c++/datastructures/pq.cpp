#include <bits/stdc++.h>
using namespace std;
struct comp{
  bool operator()(int a,int b){
    return a>b;
  }
};
int main(){
  int n;
  int a;
  cin>>n;
  priority_queue<int,vector<int>, comp> pq;
  for(int i=0;i<n;i++){
    cin>>a;
    pq.push(a);
  }
  for(int i=0;i<n;i++){
    cout<<pq.top()<<endl;
    pq.pop();
  }
}