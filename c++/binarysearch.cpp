#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];

  }
  int k;
  cin>>k;
  cout<<binary_search(v.begin(),v.end(),k)<<endl;
}