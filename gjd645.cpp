#include<iostream>
using namespace std;

int dp[1005][1005];
int v[1005],w[1005],t[1005];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i]>>t[i];
		if(t[i]==-1)t[i]=10005;
	}
	int mxx=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			int mx=dp[i-1][j];
			for(int k=0;k<=t[i]&&j-k*w[i]>=0;k++){
				mx=max(mx,dp[i-1][j-k*w[i]]+k*v[i]);
			}
			dp[i][j]=mx;
			mxx=max(mxx,dp[i][j]);
		}
	}
	cout<<mxx<<endl;
	return 0;
}

