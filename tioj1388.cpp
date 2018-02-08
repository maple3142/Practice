#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;

ll dp[105][105];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>dp[i][i];
		}
		for(int j=2;j<=n;j++){
			for(int i=j-1;i>=1;i--){
				for(int k=i;k<j;k++){
					int sz=j-i+1;
					if(sz%2==1){
						dp[i][j]=max(dp[i][j],dp[i][k]*dp[k+1][j]);
					}
					else{
						dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
					}
				}
			}
		}
		cout<<dp[1][n]<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
