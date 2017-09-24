#include<iostream>
#include<algorithm>
using namespace std;

int ar[1000001];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		int mid=ar[n/2],sum=0;
		for(int i=0;i<n;i++)
			sum+=(mid-ar[i]);
		cout<<sum<<endl;
	}
	return 0;
}

