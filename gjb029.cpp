#include<iostream>
#include<cstring>
using namespace std;
int dp[1001];
int cal(int n){
	memset(dp,0,sizeof(dp)/sizeof(dp[0]));
	dp[0]=1;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(n>=2)
			dp[i]=(int)((dp[i-2])/2.0+0.5);
		if(n>=5)
			dp[i]=(int)((dp[i-2]+dp[i-5])/2.0+0.5);
		if(n>=10)
			dp[i]=(int)((dp[i-2]+dp[i-5]+dp[i-10])/2.0+0.5);
		if(n>=20)
			dp[i]=(int)((dp[i-2]+dp[i-5]+dp[i-10]+dp[i-20])/2.0+0.5);
		if(n>=25)
			dp[i]=(int)((dp[i-2]+dp[i-5]+dp[i-10]+dp[i-20]+dp[i-25])/2.0+0.5);
		cout<<i<<":"<<dp[i]<<endl;
	}
	return dp[n];
} 
int main(void){
	int n;
	while(cin>>n){
		cout<<cal(n)<<endl;
	}
	return 0;
}

