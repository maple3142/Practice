#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

int T,n,k,idx,sumw,w;
int ar[100005];
bool ok(int w){
	int s=0,t=0;
	for(int i=0;i<n;i++){
		if(ar[i]>w)return false;
		if(s<=w)s+=ar[i];
		if(s>w){
			t++;
			i--;
			s=0;
		}
	}
	return t+1<=k;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>idx>>w;
			ar[idx]=w;
			sumw+=w;
		}
		int l=1,r=sumw;
		while(l<r){
			int mid=(l+r)/2;
			if(ok(mid))r=mid;
			else l=mid+1;
		}
		cout<<r<<endl;
	}
	return 0;
}

