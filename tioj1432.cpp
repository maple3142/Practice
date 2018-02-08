#include<iostream>
using namespace std;

int n,w;
int ar[1001];
bool ok(int x){
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		if(ar[i]>x)return false;
		if(sum<=x)sum+=ar[i];
		if(sum>x){
			sum=0;
			cnt++;
			i--;
		}
	}
	return cnt<=w;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>w){
		if(n==w&&w==0)break;
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		int l=0,r=1000000;
		while(l<r){
			int mid=(l+r)/2;
			if(ok(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}

