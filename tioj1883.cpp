#include<iostream>
#include<cstring>
using namespace std;

int cost[1005],dmg[1005],dp[100005];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int w,b,n;
		cin>>w>>b>>n;
		for(int i=0;i<n;i++){
			int a,d;
			cin>>a>>d;
			cost[i]=a;
			dmg[i]=d;
		}
		int m;
		cin>>m;
		int mx=0;
		for(int i=0;i<n;i++){
			for(int j=cost[i]+m;j<w;j++){
				dp[j]=max(dp[j],dp[j-cost[i]-m]+dmg[i]);
				mx=max(dp[j],mx);
			}
		}
		//cout<<mx<<endl;
		if(mx>=b)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}


