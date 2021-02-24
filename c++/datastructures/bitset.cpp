#include <bits/stdc++.h>
using namespace std;
int main(){
  // int n;
  // cin>>n;
  bitset<20> b;
  cout<<b<<endl;
  bitset<20> a;
  cout<<a<<endl;
  a.set(1);
  cout<<a<<endl;
  b^=a;
  b.set(5);
  b.reset(1);
  cout<<b<<endl;
}