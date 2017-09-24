#include<iostream>
#include<cstring>
using namespace std;

int max(int a,int b){
	return a>b?a:b;
}
int main(void){
	int n,m;
	while(cin>>n>>m){
		int feel[n+1],len[n+1];
		for(int i=1;i<=n;i++){
			cin>>len[i]>>feel[i];
		}
		int dp[m+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=len[i];j<=m;j++){
				dp[j]=max(dp[j],dp[j-len[i]]+feel[i]);
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}


