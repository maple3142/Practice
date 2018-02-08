#include<iostream>
#include<cstring>
using namespace std;

int a[1005],d[1005];
int dp[10005];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int w,b,n;
		cin>>w>>b>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>d[i];
		}
		int m;
		cin>>m;
		int mxdmg=0;
		for(int i=1;i<=n;i++){
			for(int j=a[i]+m;j<w;j++){
				dp[j]=max(dp[j],dp[j-a[i]-m]+d[i]);
				mxdmg=max(mxdmg,dp[j]);
			}
		}
		if(mxdmg>=b)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		memset(dp,0,sizeof(dp));
	} 
	return 0;
}

