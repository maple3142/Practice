#include<iostream>
using namespace std;

int dp[10005];
int w[3];
int main(void){
	ios::sync_with_stdio(false);
	int m,n,t;
	while(cin>>m>>n>>t){
		for(int i=1;i<=t;i++){ //dp[0]=0;dp[else]=-INF; 
			dp[i]=-0x3f3f3f3f;
		}
		for(int i=m;i<=t;i++){
			if(dp[i-m]+1>dp[i])dp[i]=dp[i-m]+1;
		}
		for(int i=n;i<=t;i++){
			if(dp[i-n]+1>dp[i])dp[i]=dp[i-n]+1;
		}
		
		int tmp=t;
		while(dp[tmp]<0)tmp--;
		cout<<dp[tmp];
		if(tmp!=t)cout<<' '<<t-tmp;
		cout<<endl;
	}
	return 0;
}

