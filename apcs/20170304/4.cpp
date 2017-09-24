#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
int ar[50005];
bool ok(int l){
	int cur=0,cnt=0;
	while(cur<n){
		int end=ar[cur]+l;
		cnt++;
		if(cnt>k)return false;
		if(ar[n-1]<=end)return true;
		while(ar[cur]<end)cur++;
	}
	return false;
}
int search(int l,int r){
	if(l==r)return l;
	int mid=(l+r)/2;
	if(ok(mid))return search(l,mid);
	else return search(mid+1,r);
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	sort(ar,ar+n);
	if(k==1)
		cout<<ar[n-1]-ar[0]<<endl;
	else
		cout<<search(1,(ar[n-1]-ar[0])/k+1)<<endl;
	return 0;
}

