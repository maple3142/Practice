#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;

int n,m;
ll dp[1<<15][15]={};
ll dfs(int now,int i,int idx,int s){
	if(idx>=m)return dp[now][i-1];
	if(!(s&(1<<idx)))return dfs(now,i,idx+1,s);
	ll rtn=dfs(now^(1<<idx),i,idx+1,s);
	if(s&(1<<(idx+1)))
		rtn+=dfs(now,i,idx+2,s);
	return rtn; 
} 
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		dp[(1<<m)-1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<m);j++){
				dp[j][i]=dfs((1<<m)-1,i,0,j);
			}
		}
		cout<<dp[(1<<m)-1][n]<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}


