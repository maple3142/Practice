#include<iostream>
using namespace std;

int ar[100001];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			if(i>=3)ar[i]=max(ar[i-2],ar[i-3])+ar[i];
		}
		if(n>=3)cout<<max(ar[n],ar[n-1])<<endl;
		else if(n==1)cout<<ar[1]<<endl;
		else cout<<max(ar[1],ar[2])<<endl;
	}
	return 0;
}
