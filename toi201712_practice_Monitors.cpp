#include<iostream>
using namespace std;

const int MX=1000005;
int n;
int ar[MX],tmp[MX];
bool ok(int x){
	copy(ar+1,ar+1+n,tmp+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(tmp[i-1]){
			cnt++;
			tmp[i]=tmp[i-1]=tmp[i+1]=0;
		}
	}
	if(tmp[n])cnt++;
	return cnt<=x;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ar[i];
	int l=0,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
/*
11
1 1 1 1 1 1 1 1 1 1 1

13
0 0 1 1 1 0 0 1 0 0 1 0 1
*/

