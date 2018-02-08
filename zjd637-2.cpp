#include<iostream>
#include<algorithm>
using namespace std;

struct item{
	int v,w;
	item(){
	} 
	item(int v,int w):v(v),w(w){
	}
}ar[10001];
int dp[10001][101];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		ar[i]=item(a,b);
	}
	int mx=0;
	for(int i=0;i<=100;i++){
		for(int j=1;j<=n;j++){
			if(i-ar[j].v<0){
				dp[j][i]=dp[j-1][i];
				continue;
			}
			dp[j][i]=max(dp[j-1][i],dp[j-1][i-ar[j].v]+ar[j].w);
			mx=max(mx,dp[j][i]);
		}
	}
	cout<<mx<<endl;
	return 0;
}

