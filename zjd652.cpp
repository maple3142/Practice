#include<iostream>
using namespace std;

const int INF=0x3f3f3f3f;

int n;
int ar[55];
int dp[55][55];
int func(int l,int r){
	if(dp[l][r])return dp[l][r];
	if(r-l<2)return 0;
	int mn=INF;
	for(int i=l+1;i<=r-1;i++){
		mn=min(mn,ar[l]*ar[i]*ar[r]+func(l,i)+func(i,r));
	}
	dp[l][r]=mn;
	return dp[l][r];
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	cout<<func(1,n)<<endl;
	return 0;
}

