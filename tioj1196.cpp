#include<iostream>
#include<cstring>
using namespace std;

int ar[15][15];
int dp[15][15];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		char c;
		for(int i=0;i<=n;i++){
			dp[0][i]=dp[i][0]=-0x3f3f3f3f;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c;
				if(c<='9' && c>='0'){
					ar[i][j]=c-'0';
				}
				if(c=='X'){
					ar[i][j]=-0x3f3f3f3f;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i-1][j]>=0 || dp[i][j-1]>=0)
					dp[i][j]=max(dp[i-1][j],dp[i][j-1])+ar[i][j];
				else dp[i][j]=-0x3f3f3f3f;
				dp[1][1]=0;
			}
		}
		if(dp[n][n]>=0)cout<<dp[n][n]<<endl;
		else cout<<'X'<<endl;
		memset(ar,0,sizeof(ar));
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

