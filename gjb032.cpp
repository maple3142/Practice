#include<iostream>
using namespace std;

int ar[101];
int dp[101];
int max(int a){
	int mx=1;
	for(int i=1;i<a;i++){
		if(ar[i]<ar[a])
			if(dp[i]+1>mx)
				mx=dp[i]+1;
	}
	return mx;
}
int main(void){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>ar[i];
		dp[1]=1;
		int mx=0;
		for(int i=1;i<=n;i++){
			dp[i]=max(i);
			if(dp[i]>mx)
				mx=dp[i];
		}
		cout<<mx<<endl;
	}
	
	return 0;
}


