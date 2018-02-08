#include<iostream>
#include<algorithm>
using namespace std;

const int MX=50005;
int ar[MX],ar2[MX];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>ar[i];
		sort(ar,ar+n);
		for(int i=0;i<n-1;i++)ar2[i]=ar[i+1]-ar[i];
		sort(ar2,ar2+n-1);
		int sum=0;
		for(int i=0;i<n-m;i++)sum+=ar2[i];
		cout<<sum<<endl;
	}
	return 0;
}

