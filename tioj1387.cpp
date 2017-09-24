#include<iostream>
using namespace std;

const int N=60;
int w[N],m[N],c[N];
int dp[10001];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i]>>m[i]>>c[i];
	}
	int v;
	cin>>v;
	for(int i=0;i<n;i++){
		for(int j=v;j>=0;j--){
			for(int k=1;k<=c[i];k++){
				if(j<k*w[i])continue;
				dp[j]=max(dp[j],dp[j-k*w[i]]+k*m[i]);
			}
		}
	}
	cout<<dp[v]<<endl;
	return 0;
}

