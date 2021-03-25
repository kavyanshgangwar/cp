#include <bits/stdc++.h>
using namespace std;
bool check(string s1,string s2, string x){
  int x1 = x.size();
  int n1 = s1.size();
  int n2 = s2.size();
  int p = n1/x1;
  int e = n2/x1;
  string A="";
  string B="";
  while(p){
    A+=x;
    p--;
  }
  while(e){
    B+=x;
    e--;
  }
  return (A==s1 && B==s2);
}
int main(){
  string s1,s2;
  cin>>s1>>s2;
  string x = "";
  if(s1.size()>s2.size()){
    swap(s1,s2);
  }
  int n1 = s1.size();
  int n2 = s2.size();
  int cnt=0;
  for(int i=0;i<n1;i++){
    x+=s2[i];
    int x1 = x.size();
    cnt+=(n2%x1==0 && n1%x1==0 && check(s1,s2,x));

  }
  cout<<cnt<<endl;
}