#include<iostream>
using namespace std;

int dp[8001];
const int coins[]={1,13,33,43,139,169,1309,2597};
int main(void){
	ios::sync_with_stdio(false);
	dp[0]=1;
	for(int i=0;i<8;i++){
		for(int x=1;x<=8000;x++){
			if(x-coins[i]>=0){
				dp[x]+=dp[x-coins[i]];
			}
		}
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}

