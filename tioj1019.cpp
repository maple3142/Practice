#include<iostream>
using namespace std;
typedef long long int ll;

int n,T;
ll ar[1001];
ll dp[1001];
int main(void){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		dp[1]=abs(ar[1]-ar[0]);
		for(int i=2;i<n;i++){
			dp[i]=min(dp[i-1]+abs(ar[i]-ar[i-1]),dp[i-2]+abs(ar[i]-ar[i-2]));
		}
		cout<<dp[n-1]<<endl;
	}
	return 0;
}

