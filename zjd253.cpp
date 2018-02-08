#include<iostream>
using namespace std;

int dp[7490];
const int coins[]={1,5,10,25,50};
int main(void){
	ios::sync_with_stdio(false);
	dp[0]=1;
	for(int i=0;i<5;i++){
		for(int x=1;x<=7489;x++){
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

