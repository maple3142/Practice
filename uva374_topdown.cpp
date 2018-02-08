#include<iostream>
using namespace std;
typedef long long int ll;

ll fff(ll b,ll p,ll m){
	if(p==1)return b%m;
	ll x=fff(b,p/2,m)*fff(b,p/2,m)%m;
	if(p%2!=0)x*=b%m;
	x%=m;
	return x;
}
int main(void){
	ios::sync_with_stdio(false);
	ll b,p,m;
	while(cin>>b>>p>>m){
		cout<<fff(b,p,m)<<endl;
	}
	return 0;
}

