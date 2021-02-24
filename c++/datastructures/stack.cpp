#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  stack<int> s;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    s.push(a);
  }
  for(int i=0;i<n;i++){
    cout<<s.top()<<endl;
    s.pop();
  }
}