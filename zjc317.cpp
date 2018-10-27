#include<iostream>
#include<cstring>
using namespace std;

int dp[1001]={};
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,a,b;
		cin>>n>>a>>b;
		dp[0]=dp[a]=dp[b]=1;
		for(int i=max(a,b);i<=n;i++){
			dp[i]=dp[i-a]+dp[i-b];
		}
		cout<<(dp[n]==0?-1:dp[n])<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

