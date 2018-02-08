#include<iostream>
#include<cstring>
using namespace std;

string s;
int n,r,c;
int ar[105][105];
int dp[105][105];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int dfs(int x,int y){
	if(dp[x][y]!=0)return dp[x][y]+1;
	int mx=0;
	for(int i=0;i<4;i++){
		int xx=x+X[i];
		int yy=y+Y[i];
		if(ar[xx][yy]<=ar[x][y])continue;
		if(xx<1||xx>r)continue;
		if(yy<1||yy>c)continue;
		mx=max(mx,dfs(xx,yy));
	}
	dp[x][y]=mx;
	return mx+1;
} 
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>s>>r>>c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>ar[i][j];
			}
		}
		
		int mx=0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				mx=max(dfs(i,j),mx);
			}
		}
		cout<<s<<": "<<mx<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

