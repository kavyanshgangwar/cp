#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[310][310][310][2];
ll a[310][310];
ll r,c,d;
ll f(int i,int j,int cnt,int dn){
	if(i==r-1 && j==c-1){
		return 1;
	}
	if(i>r-1 || j>c-1|| a[i][j]==0){
		return 0;
	}
	if(dp[i][j][cnt][dn]==-1){
	ll x=0;
	if(a[i][j]==1){
		if(dn==1){
			if(cnt<d){
				x = (x+f(i+1,j,cnt+1,dn))%20011;
			}
			x = (x + f(i,j+1,1,(dn+1)%2))%20011;
		}else{
			if(cnt<d){
				x=(x+f(i,j+1,cnt+1,dn))%20011;
			}
			x = (x+f(i+1,j,1,1))%20011;
		}
	}
	dp[i][j][cnt][dn] = x%20011;}
	return dp[i][j][cnt][dn];
}
int main(){
	cin>>r>>c>>d;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
		cin>>a[i][j];
	}
	memset(dp,-1,sizeof dp);
	cout<<f(0,0,0,0)<<endl;
}