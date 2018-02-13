#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int,ll> pii;

pii ar[100005];
pii dp[100005];
bool ok[18]={1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,1,0};
inline bool check(int a,int b){
	return b-a>=18||ok[b-a];
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		ar[i]=pii(b,a);
	}
	sort(ar+1,ar+1+n);
	//dp[i]=max(dp[i-4],dp[i-7])+ar[i]
	dp[1]=check(0,ar[1].first)?ar[1]:pii(0,0);
	ll ans=dp[1].second;
	for(int i=2;i<=n;i++){
		ll mx=0;
		for(int j=1;j<=18&&i-j>=1;j++){
			if(!check(dp[i-j].first,ar[i].first))continue;
			mx=max(mx,dp[i-j].second);
		}
		dp[i]=pii(ar[i].first,mx+ar[i].second);
		//cout<<dp[i].first<<','<<dp[i].second<<endl;
		ans=max(dp[i].second,ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
25 25
1 1
1 2
1 3
100 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
1 16
1 17
1 18
1 19
1 20
100 21
1 22
1 23
1 24
1 25
*/

