#include<iostream>
using namespace std;

const int MX=300005;

int ar[MX];
int dp[MX];
bool willTalk(int a,int b){
	if(a==b)return true;
	if(a<0&&b<0)return true;
	if(a>0&&b>0)return true;
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ar[i];
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(willTalk(ar[i],ar[i-1]))dp[i]=1;
		else dp[i]=dp[i-1]+1;
	}
	int mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
	cout<<mx<<endl;
	return 0;
}


