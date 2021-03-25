#include <bits/stdc++.h>
using namespace std;
int c = 0;
class Node{
  public:
  Node* v[26];
  bool a[26];
  // int num;
  Node(){
    for(int i=0;i<26;i++){
      v[i]=nullptr;
      a[i]=false;
    }
    // num = c;
  }
  int count(){
    int cnt=0;
    for(int i=0;i<26;i++){
      if(a[i]){
        cnt++;
      }
      if(v[i]!=nullptr){
        cnt+=v[i]->count();
      }
    }
    // cout<<num<<" "<<cnt<<endl;
    return cnt;
  }
};
int main(){
  string s;
  cin>>s;
  string t;
  cin>>t;
  int k;
  cin>>k;
  int n=s.size();
  Node* head = new Node();
  // c++;
  Node* cur;
  int cnt;
  for(int i=0;i<n;i++){
    cur = head;
    cnt=0;
    for(int j=i;j<n;j++){
      
      if(t[s[j]-'a']=='0'){
        cnt++;
        if(cnt>k){
          break;
        }
      }
      cur->a[s[j]-'a']=true;
      if(cur->v[s[j]-'a']){
        cur = cur->v[s[j]-'a'];
      }else{
        
        cur->v[s[j]-'a'] = new Node();
        // c++;
        cur = cur->v[s[j]-'a'];
      }
      
    }
  }
  cout<<head->count()<<endl;
}