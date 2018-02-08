#include<iostream>
using namespace std;

int w[55];
int m[55];
int c[55];
int dp[2][10005];
int main(void){
	ios::sync_with_stdio(false);
	int n,t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>m[i]>>c[i];
	}
	cin>>t;
	for(int i=1;i<=n;i++){
		int num=min(c[i],t/w[i]);
		for(int k=1;num;k*=2){
			if(k>num)k=num;
			num-=k;
			for(int j=0;j<=t;j++){
				if(j-w[i]*k<0){
					dp[i%2][j]=dp[(i+1)%2][j];
					continue;
				}
				dp[i%2][j]=max(dp[(i+1)%2][j],dp[(i+1)%2][j-w[i]*k]+m[i]*k);
				//cout<<i<<" "<<j<<" "<<dp[i%2][j]<<endl;
			}
		}
		/*
		for(int j=0;j<=t;j++){
			int mx=dp[(i+1)%2][j];
			for(int k=1;k<=c[i]&&j-w[i]*k>=0;k++){
				mx=max(mx,dp[(i+1)%2][j-w[i]*k]+m[i]*k);
			}
			dp[i%2][j]=mx;
		}
		*/
	}
	cout<<dp[n%2][t]<<endl;
	return 0;
}

