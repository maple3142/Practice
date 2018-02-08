#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX=10001;

int ar[MX];
int dp1[MX];
int dp2[MX];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)cin>>ar[i];
		
		vector<int> v;
		v.push_back(ar[1]);
		dp1[1]=1;
		for(int i=2;i<=n;i++){
			if(ar[i]>v.back())v.push_back(ar[i]);
			else *lower_bound(v.begin(),v.end(),ar[i])=ar[i];
			dp1[i]=v.size();
		}
		v.clear();
		v.push_back(ar[n]);
		dp2[n]=1;
		for(int i=n-1;i>=1;i--){
			if(ar[i]>v.back())v.push_back(ar[i]);
			else *lower_bound(v.begin(),v.end(),ar[i])=ar[i];
			dp2[i]=v.size();
		}
		/*
		for(int i=1;i<=n;i++)cout<<dp1[i]<<' ';
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<dp2[i]<<' ';
		cout<<endl;
		*/
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,min(dp1[i],dp2[i]));
		}
		cout<<2*mx-1<<endl;
	}
	return 0;
}

