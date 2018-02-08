#include<iostream>
using namespace std;

int v[101];
int w[101];
int dp[10001][101];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	int mx=0;
	for(int i=0;i<=100;i++){
		for(int j=1;j<=n;j++){
			if(i-v[j]<0)continue;
			dp[j][i]=max(dp[j-1][i],dp[j-1][i-v[j]]+w[j]);
			mx=max(mx,dp[j][i]);
		}
	}
	cout<<mx<<endl;
	return 0;
}

