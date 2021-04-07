#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[310][310][310];
ll n;
ll a[310];
ll f(int pos,int i,int j){
	if(pos>=n+2){
		return 0;
	}
	if(dp[pos][i][j]==-1){
		dp[pos][i][j] = f(pos+1,i,j);
		if(a[pos]>a[i]){
			dp[pos][i][j] = max(dp[pos][i][j],1+f(pos+1,pos,j));
		}
		if(a[pos]<a[j]){
			dp[pos][i][j] = max(dp[pos][i][j],1+f(pos+1,i,pos));
		}
	}
	return dp[pos][i][j];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=2;i<n+2;i++){
			cin>>a[i];
		}
		memset(dp,-1,sizeof dp);
		a[0]=INT32_MIN;
		a[1]=INT32_MAX;
		cout<<f(2,0,1)<<endl;
	}
}