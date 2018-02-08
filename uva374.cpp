#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;

inline int abmodp(int a,int b,int p){
	return (a%p*b%p)%p;
}
ll dp[33];
ll pow2[33];
int main(void){
	ios::sync_with_stdio(false);
	pow2[0]=1;
	for(int i=1;i<=32;i++){
		pow2[i]=pow2[i-1]*2;
	}
	ll b,p,m;
	while(cin>>b>>p>>m){
		dp[0]=b%m;
		for(int i=1;i<=32;i++){
			dp[i]=abmodp(dp[i-1],dp[i-1],m);
			//cout<<i<<' '<<dp[i]<<endl;
		}
		ll sum=1;
		for(int i=32;i>=0;i--){
			if(p>=pow2[i]){
				sum*=dp[i];
				sum%=m;
				p-=pow2[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

