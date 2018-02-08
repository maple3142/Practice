#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;

const ll MOD=10000019;
ll ar[1000005];
ll b[1000005];
ll n;
ll count(ll left,ll right){
	if(left+1==right)return 0;
	ll mid=(left+right)/2;
	ll cnt=(count(left,mid)%MOD+count(mid,right)%MOD)%MOD;
	ll l=left,r=mid,k=left,lst=0;
	for(;l<mid;l++){
		ll x;
		if(l>left)
			x=lst+(r-mid)*(ar[l]-ar[l-1]);
		else
			x=lst;
		while(r<right&&ar[r]<ar[l]){
			x+=(ar[r]+ar[l])%MOD;
			x%=MOD;
			r++;
		}
		cnt+=x;
		cnt%=MOD;
		lst=x;
	}
	/*for(;l<mid;l++){
		while(r<right&&ar[r]<ar[l]){
			cnt+=(ar[r]+ar[l])%MOD;
			cnt%=MOD;
			r++;
		}
		r=mid;
	}*/
	l=left;
	r=mid;
	while(l<mid||r<right){
		if(l<mid&&(r>=right||ar[l]<=ar[r]))
			b[k++]=ar[l++];
		else
			b[k++]=ar[r++];
	}
	for(ll i=left;i<right;i++)
		ar[i]=b[i];
	return cnt;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>ar[i];
	}
	cout<<count(0,n)<<endl;
	return 0;
}
