#include<iostream>
using namespace std;

string t,r;
int n,k,i;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>k){
		for(i=1;i<=n;i++){
			if(i==n-k+1)cin>>r;
			else cin>>t;
		}
		cout<<r<<'\n';
	}
	return 0;
}

