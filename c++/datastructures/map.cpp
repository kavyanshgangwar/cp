#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<string,int> m;
  string s;
  int a;

  for(int i=0;i<n;i++){
    cin>>s>>a;
    m[s]=a;
  }

  for(int i=0;i<n;i++){
    cin>>s;
    if(m.find(s)!=m.end()){
      cout<<m[s]<<endl;
    }else{
      cout<<"not found!\n";
    }
  }
}