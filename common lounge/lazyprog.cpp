// smallest a must be done first and we must start from last d
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pfii pair<float,pair<int,int> >

bool comp(pfii &a, pfii &b){
  if(a.s.s == b.s.s){
    return a.f>b.f;
  }else{
    return a.s.s > b.s.s;
  }
}

struct c{
  bool operator()(pfii &a, pfii &b){
    return a.f<b.f;
  }
};
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    pfii p[n];
    for(int i=0;i<n;i++){
      cin>>p[i].f>>p[i].s.f>>p[i].s.s;
    }
    sort(p,p+n,comp);
    priority_queue<pfii,vector<pfii>, c> q;
    int cur = p[0].s.s;
    q.push(p[0]);
    int i=1;
    float ans =0 ;
    while(!q.empty()){
      auto x = q.top();
      // cout<<x.s.s<<" ";
      q.pop();
      if(cur-x.s.f>=0){
        cur-=x.s.f;
      }else if(cur>=0){
        ans+= ((float)(x.s.f - cur) / x.f);
        cur = 0;
      }
      if(i<n)
      while(cur<=p[i].s.s){
        q.push(p[i]);
        i++;
        if(i==n)break;
      }
    }
    printf("%.2f\n",ans);
  }
}