#include<iostream>
using namespace std;

int ar[1001]={};
int sum[1001]={};
int dp[1001][1001]={};
int max(int a,int b){
	return a>b?a:b;
}
int f(int l,int r){
	if(dp[l][r]!=0)return dp[l][r];
	if(l==r)return ar[l];
	return dp[l][r]=max((sum[r]-sum[l]) - f(l+1,r) + ar[l] , (sum[r-1]-sum[l-1]) - f(l,r-1) + ar[r]);
}
int main(void){
	ios::sync_with_stdio(false);
	int l,n;
	while(cin>>n){
		sum[0]=0;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			sum[i]=sum[i-1]+ar[i];
		}
		f(1,n);
		cout<<dp[1][n]<<" "<<sum[n]-dp[1][n]<<endl;
	}
	return 0;
}


