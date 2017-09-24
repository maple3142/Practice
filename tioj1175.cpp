#include<iostream>
using namespace std;

int dp[100005];
int ar[100005];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>ar[i];
		for(int i=0;i<n;i++){
			int mx=0;
			for(int j=0;j<i;j++){
				if(ar[i]>ar[j])
					mx=max(dp[j],mx);
			}
			dp[i]=mx+1;
		}
		int mx=0;
		for(int i=0;i<n;i++){
			mx=max(dp[i],mx);
		}
		cout<<mx<<endl;
	}
	return 0;
}


