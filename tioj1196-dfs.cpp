#include<iostream>
#include<cstring>
using namespace std;

bool ok=false;
int ar[15][15];
int dp[15][15];
int dfs(int x,int y){
	if(ar[x][y]<0)return 0;
	if(x==y&&x==1)ok=true;
	if(dp[x][y])return dp[x][y];
	int mx=0;
	if(x>1)mx=max(mx,dfs(x-1,y));
	if(y>1)mx=max(mx,dfs(x,y-1));
	dp[x][y]=mx+ar[x][y];
	return mx+ar[x][y];
}
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
		int r=dfs(n,n);
		if(ok)cout<<r<<endl;
		else cout<<'X'<<endl;
		memset(ar,0,sizeof(ar));
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

