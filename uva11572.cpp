#include<iostream>
#include<unordered_map>
using namespace std;

const int MX=1000005;

int ar[MX];
int dp[MX];
unordered_map<int,int> mp;
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			dp[i]=0;
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			if(mp[ar[i]]){
				int st=i-dp[i-1];
				int d=mp[ar[i]]-st;
				if(d<0)d=-1;
				//cout<<i<<' '<<dp[i-1]<<' '<<st<<' '<<d<<endl;
				dp[i]=dp[i-1]-d;
			}
			else{
				dp[i]=dp[i-1]+1;
			}
			mp[ar[i]]=i;
			mx=max(mx,dp[i]);
		}
		cout<<mx<<endl;
		mp.clear();
	}
	return 0;
}

