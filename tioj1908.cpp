#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;

int max(ll a,int b){
	return a>b?a:b;
}
int n;
int ar[12][12]={};
ll dp[1<<12][12]={};
int o(int s){
	int x=1<<s;
	if(s!=0)x=x|(1<<(s-1));
	if(s!=n-1)x=x|(1<<(s+1));
	return x;
}
ll dfs(int now,int i,int idx,int s){
	if(idx>=n)return dp[(1<<n)-1-now][i-1];
	if(!(s&(1<<idx)))return dfs(now,i,idx+1,s);
	ll rtn=dfs(now|o(idx),i,idx+2,s)+ar[i][idx+1];
	rtn=max(rtn,dfs(now,i,idx+1,s));
	return rtn;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cin>>ar[i][j];
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<n);j++){
				dp[j][i]=dfs(0,i,0,j);
				mx=max(dp[j][i],mx);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}


