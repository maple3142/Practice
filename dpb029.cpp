#include<iostream>
#include<cstring>
using namespace std;

int dp[1001];
int money[5]={2,5,10,20,25};
int main(void){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int j=4;j>=0;j--){
		for(int i=money[j];i<1001;i++){
			dp[i]+=dp[i-money[j]];
		}
	}
		
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}


