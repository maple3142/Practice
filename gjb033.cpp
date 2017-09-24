#include<iostream>
#include<cstring>
using namespace std;

int max(int a,int b){
	return a>b?a:b;
}
int main(void){
	string a,b;
	while(cin>>a>>b){
		int dp[a.length()+1][b.length()+1],mx=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=a.length();i++){
			for(int j=1;j<=b.length();j++){
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				mx=max(mx,dp[i][j]);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}


