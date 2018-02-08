#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;

int dis[17][17];
int dp[16][(1<<16)+5];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int a;
		cin>>a;
		for(int i=0;i<a-1;i++){
			for(int j=i+1;j<a;j++){
				cin>>dis[i][j];
				dis[j][i]=dis[i][j];
			}
		}
		for(int n=0;n<a;n++){
			for(int s=0;s<(1<<a);s++){
				dp[n][s]=0x3f3f3f3f;
			}
		}
		dp[0][0]=0;
		for(int s=0;s<(1<<a);s++){
			for(int n=0;n<a;n++){
				int mn=0x3f3f3f3f;
				if(!(s&(1<<n)))continue;
				if(n==s&&s==0)continue;
				if(s == (1<<n)){
					dp[n][s]=dis[0][n];
					continue;
				}
				for(int i=0;i<a;i++){
					if(n!=i && s&(1<<i))
						mn=min(mn,dp[i][s-(1<<n)]+dis[i][n]);
				}
				dp[n][s]=mn;
			}
		}
		cout<<dp[0][(1<<a)-1]<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

