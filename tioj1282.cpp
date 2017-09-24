#include<iostream>
#include<algorithm>
#define mid ((l+r)/2)
typedef long long int ll;
using namespace std;

ll ar[100000+5];
struct seg{
	seg *lc,*rc;
	ll gcd;
	ll sum;
	seg(){
		sum=0;
		gcd=1;
	}
}*t;
void pull(seg *t){
	t->gcd=__gcd(t->lc->gcd,t->rc->gcd);
	t->sum=t->lc->sum + t->rc->sum;
}
seg* build(ll l,ll r){
	seg *t=new seg();
	if(l==r){
		t->sum=ar[l];
		if(t->sum<0)
			t->gcd=-1*t->sum;
		else
			t->gcd=t->sum;
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	pull(t);
	return t;
}
void change(seg *now,ll pos,ll val,ll l,ll r){
	if(l==r){
		now->sum+=val;
		if(now->sum<0)
			now->gcd=-1*now->sum;
		else
			now->gcd=now->sum;
		return;
	}
	if(pos<=mid)
		change(now->lc,pos,val,l,mid);
	else
		change(now->rc,pos,val,mid+1,r);
	pull(now);
}
ll queryGCD(seg *now,ll ql,ll qr,ll l,ll r){
	if(ql==l && qr==r){
		return now->gcd;
	}
	if(ql>mid){
		return queryGCD(now->rc,ql,qr,mid+1,r);
	}
	else if(qr<=mid){
		return queryGCD(now->lc,ql,qr,l,mid);
	}
	else{
		return __gcd(queryGCD(now->lc,ql,mid,l,mid) , queryGCD(now->rc,mid+1,qr,mid+1,r));
	}
}
ll querySUM(seg *now,ll ql,ll qr,ll l,ll r){
	if(ql<=l && qr>=r)return now->sum;
	else if(ql>r || qr<l)return 0;
	else return querySUM(now->lc,ql,qr,l,mid)+querySUM(now->rc,ql,qr,mid+1,r);
}
int main(void){
	ios::sync_with_stdio(false);
	ll n,m;
	while(cin>>n>>m){
		ar[0]=0;
		ll last=0;
		for(ll i=1;i<=n;i++){
			ll x;
			cin>>x;
			ar[i]=x-last;
			last=x;
		}
		t=build(1,n);
		for(ll i=0;i<m;i++){
			ll p;
			cin>>p;
			switch(p){
				case 1:
					ll l,r,k;
					cin>>l>>r>>k;
					change(t,l,k,1,n);
					if(r+1<=n)
						change(t,r+1,-1*k,1,n);
					break;
				case 2:
					ll e,c;
					cin>>e>>c;
					ll frontsum=querySUM(t,1,e,1,n);
					if(e==c){
						cout<<frontsum<<endl;
						break;
					}
					ll backgcd=queryGCD(t,e+1,c,1,n);
					cout<<__gcd(backgcd,frontsum)<<endl;
					break;
			}
		}
	}
	return 0;
}



