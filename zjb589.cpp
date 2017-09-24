#include<iostream>
#include<cstring>
using namespace std;

int ar[41],dp[41];

int main(void){
	cin.sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>ar[i];
		dp[0]=0;
		for(int i=1;i<=n+1;i++){
			dp[i]=dp[i-1]+max(ar[i-1]*2,ar[i-1]+ar[i]);
		}	
		cout<<dp[n+1]<<endl;
		memset(ar,0,sizeof(ar));
	}
	return 0;
}


