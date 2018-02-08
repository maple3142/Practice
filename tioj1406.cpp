#include<iostream>
using namespace std;
typedef long long int ll;

ll n;
ll loc[100005];
ll fish[100005];
bool ok(ll avg){
	ll p=fish[0]-avg;
	for(int i=1;i<n;i++){
		if(p>=0)p=max(p+loc[i-1]-loc[i],0ll);
		else p+=loc[i-1]-loc[i];
		p+=fish[i]-avg;
	} 
	return p>=0;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		ll p,f,l=0,r=0;
		for(int i=0;i<n;i++){
			cin>>loc[i]>>fish[i];
			r=max(fish[i],r);
		}
		r++;
		while(r-l>1){
			ll mid=(l+r)/2;
			if(ok(mid))l=mid;
			else r=mid;
		}
		cout<<l<<endl;
	}
	return 0;
}

