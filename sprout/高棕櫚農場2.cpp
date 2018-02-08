#include<iostream>
#include<cstring>
using namespace std;

int value[105];
int cost[105];
int eat[2][1000001];
int dp[2][1000001];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			cin>>cost[i]>>value[i];
		}
		int mx=0;
		for(int i=0;i<n;i++){
			for(int v=0;v<=m;v++){
				if(v<cost[i]||eat[i%2][v]>k)dp[i%2][v]=dp[(i+1)%2][v];
				else{
					if(dp[(i+1)%2][v-cost[i]]+value[i]>dp[i%2][v]){
						eat[(i+1)%2][v]=eat[(i+1)%2][v-cost[i]]+1;
						dp[i%2][v]=dp[(i+1)%2][v-cost[i]]+value[i];
					}
					else dp[i%2][v]=dp[(i+1)%2][v];
				}
				if(eat[i%2][v]<=k)mx=max(dp[i%2][v],mx);
			}
		}
		cout<<mx<<endl;
		memset(dp,0,sizeof(dp));
		memset(eat,0,sizeof(eat));
	}
	return 0;
}
