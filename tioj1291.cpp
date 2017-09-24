#include<iostream>
using namespace std;
typedef long long int ll;

const int mod=1000000;
ll dp[201][201];
int main(void){
	ios::sync_with_stdio(false);
	dp[0][0]=1;
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			dp[i][j]=(dp[i-1][j-1]+(i*dp[i][j-1])%mod)%mod;
		}
	}
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum=(sum+dp[i][m])%mod;
		}
		cout<<sum<<endl;
	}
	return 0;
}

