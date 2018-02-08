#include<iostream>
using namespace std;

int ar[100001];
int rangemax(int l,int r){
	int mx=0;
	for(int i=l;i<=r;i++){
		mx=max(mx,ar[i]);
	}
	return mx;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		if(n>k){
			for(int i=1;i<=n;i++){
				int l=i-2*k,r=i-k;
				if(l<1)l=0;
				if(r<1)r=0;
				ar[i]=rangemax(l,r)+ar[i];
			}
			//cout<<max(ar[n],ar[n-1])<<endl;
		}
		if(true){
			int mx=0;
			for(int i=1;i<=n;i++){
				mx=max(mx,ar[i]);
			}
			cout<<mx<<endl;
		}
	}
	return 0;
}
