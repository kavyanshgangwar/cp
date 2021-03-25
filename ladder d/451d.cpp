#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  cin>>s;
  int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='a'){
      if(i%2==0){
        cnt1++;
      }else{
        cnt2++;
      }
    }else{
      if(i%2==0){
        cnt3++;
      }else{
        cnt4++;
      }
    }
  }
  cout<<cnt1*cnt2+cnt3*cnt4<<" ";
  cout<<(cnt1*(cnt1-1))/2+(cnt2*(cnt2-1))/2+(cnt3*(cnt3-1))/2+(cnt4*(cnt4-1))/2+cnt1+cnt2+cnt3+cnt4;
  cout<<endl;
}