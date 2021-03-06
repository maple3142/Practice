#include<iostream>
using namespace std;

int coins[]={1,5,10,12,16,20};
int dp[105];
int main(void){
	ios::sync_with_stdio(false);
	for(int i=1;i<=100;i++){
		int mn=0x3f3f3f3f;
		for(int j=0;j<6;j++){
			int c=coins[j];
			if(i-c<0)continue;
			mn=min(mn,dp[i-c]);
		}
		dp[i]=mn+1;
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}

