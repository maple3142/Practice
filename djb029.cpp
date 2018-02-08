#include<iostream>
using namespace std;

int coins[]={2,5,10,20,25};
int dp[1005];
int main(void){
	ios::sync_with_stdio(false);
	dp[0]=1;
	for(int j=0;j<5;j++){
		int c=coins[j];
		for(int i=1;i<=1000;i++){
			if(i-c<0)continue;
			dp[i]+=dp[i-c];
		}
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}

