#include<iostream>
using namespace std;

const int LMX=2000;
int dp[5005][LMX];
int main(void){
	ios::sync_with_stdio(false);
	dp[1][0]=1;
	for(int i=2;i<=5000;i++){
		for(int j=0;j<LMX;j++){
			dp[i][j]+=(dp[i-1][j]+dp[i-2][j]);
			if(dp[i][j]>=10){
				dp[i][j+1]+=dp[i][j]/10;
				dp[i][j]%=10;
			}
		}
	}
	int n;
	while(cin>>n){
		cout<<"The Fibonacci number for "<<n<<" is ";
		
		if(n==0)cout<<0<<endl;
		else{
			int t=-1;
			for(int i=LMX-1;i>=0;i--){
				if(dp[n][i]==0)continue;
				t=i;
				break;
			}
			for(int i=t;i>=0;i--){
				cout<<dp[n][i];
			}
			cout<<endl;
		}
	}
	return 0;
}

