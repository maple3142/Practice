#include<iostream>
using namespace std;

int ar[101];
int dp[101];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			dp[i]=dp[i+1]=dp[i+2]=0;
		}
		for(int i=1;i<=n;i++){
			dp[i+1]=max(dp[i+1],dp[i]+ar[i]);
			dp[i+2]=max(dp[i+2],dp[i]+2*ar[i]);
		}
		cout<<max(dp[n+1],dp[n+2])<<endl;
	}
	return 0;
}

