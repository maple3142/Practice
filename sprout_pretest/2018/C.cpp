#include<iostream>
using namespace std;
typedef long long int ll;

int ar[100005];
ll abs(ll a){
	return a>0?a:-a;
}
int xx[100005];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		xx[ar[i]]=i;
	}
	ll sum=0;
	for(int i=n;i>=1;i--){
		int mxi=xx[i];
		swap(xx[ar[mxi]],xx[ar[i]]);
		swap(ar[mxi],ar[i]);
		sum+=abs(mxi-i);
	}
	cout<<sum<<endl;
	return 0;
}

