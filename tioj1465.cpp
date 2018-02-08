#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long int ll;

ll T,m,k;
ll ar[505];
vector<ll> s[505];
bool ok(ll x){
	ll cur=1,time=0;
	for(ll i=1;i<=m;i++){
		time+=ar[i];
		if(time>x){
			i--;
			cur++;
			time=0;
		}
		if(cur>k)return false;
	}
	return cur<=k;
}
void getans(ll x){
	ll cur=k,time=0;
	for(ll i=m;i>=1;i--){
		time+=ar[i];
		s[cur].push_back(ar[i]);
		if(time>x){
			s[cur].pop_back();
			i++;
			cur--;
			time=0;
		}
		if(i<=cur){
			cur--;
			time=0;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>m>>k;
		ll sum=0;
		for(ll i=1;i<=m;i++){
			cin>>ar[i];
			sum+=ar[i]; 
		}
		ll l=0,r=sum;
		while(l<r){
			ll mid=(l+r)/2;
			if(ok(mid))r=mid;
			else l=mid+1;
		}
		getans(l);
		for(ll i=1;i<=k;i++){
			for(ll j=s[i].size()-1;j>=0;j--)cout<<s[i][j]<<' ';
			if(i!=k)cout<<"/ ";
		}
		cout<<endl;
		
		memset(s,0,sizeof(s));
	}
	return 0;
}

