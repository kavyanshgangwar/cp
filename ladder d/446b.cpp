#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0);
  int n,m,k,p;
  cin>>n>>m>>k>>p;
  int a[n][m];
  int row[n]={0};
  int col[m]={0};
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
      row[i]+=a[i][j];
      col[j]+=a[i][j];
    }
  }
  int cnt = 1000000000000000000;
  cnt*=-1;
  int r[k+1] = {0};
  int c[k+1] = {0};
  priority_queue<int> q1,q2;
  for(int i=0;i<n;i++){
    q1.push(row[i]);
  }
  for(int i=0;i<m;i++){
    q2.push(col[i]);
  }
  int ans[k+1];
  for(int i=1;i<=k;i++){
    int z = q1.top();
    q1.pop();
    r[i]=z+r[i-1];
    q1.push(z-m*p);
    z = q2.top();
    q2.pop();
    c[i]=z+c[i-1];
    q2.push(z-n*p);
  }
  for(int i=0;i<=k;i++){
    ans[i]=r[i]+c[k-i];
    cnt = max(cnt,ans[i]-(k-i)*i*p);
  }
  cout<<cnt<<endl;
}