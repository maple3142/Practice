#include<iostream>
using namespace std;

int dp[1005][1005];
int main(void){
	ios::sync_with_stdio(false);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	dp[0][0]=0;
	for(int i=1;i<=a.length();i++){
		dp[i][0]=i;
	}
	for(int i=1;i<=b.length();i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[a.length()][b.length()]<<endl;
	return 0;
}


