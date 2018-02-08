#include<iostream>
using namespace std;

int l[105];
int s[105];
int dp[2][1005];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>s[i];
	}
	int mx=0;
	for(int j=1;j<=n;j++){
		for(int i=l[j];i<=m;i++){
			dp[j%2][i]=max(dp[(j+1)%2][i],dp[j%2][i-l[j]]+s[j]);
			/*
			int k=0,mxx=0;
			while(true){
				if(i-l[j]*k<0){
					break;
				}
				mxx=max(mxx,dp[(j+1)%2][i-l[j]*k]+s[j]*k);
				k++;
			}
			dp[j%2][i]=mxx;
			*/
			mx=max(mx,dp[j%2][i]);
		}
	}
	cout<<mx<<endl;
	return 0;
}

