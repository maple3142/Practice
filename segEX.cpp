#include<iostream>
#include<cmath>
#define mid ((l+r)/2)
typedef long long ll;
using namespace std;

ll ar[100000+5];
struct seg{
	seg *lc,*rc;
	ll max;
	ll sum;
	seg(){
		max=sum=0;
	}
}*t;
void pull(seg *t){
	t->max=max(t->lc->max,t->rc->max);
	t->sum=t->lc->sum + t->rc->sum;
}
seg* build(ll l,ll r){
	seg *t=new seg();
	if(l==r){
		t->sum=t->max=ar[l];
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	pull(t);
	return t;
}
void change(seg *now,ll pos,ll val,ll l,ll r){
	if(l==r){
		now->max=now->sum=val;
		return;
	}
	if(pos<=mid)
		change(now->lc,pos,val,l,mid);
	else
		change(now->rc,pos,val,mid+1,r);
	pull(now);
}
void SQRT(seg *now,ll ql,ll qr,ll l,ll r){
	if(ql>r || qr<l || now->max==1)return;
	if(l==r){
		now->max=now->sum=(ll)sqrt(now->sum);
		return;
	}
	SQRT(now->lc,ql,qr,l,mid);
	SQRT(now->rc,ql,qr,mid+1,r);
	pull(now);
}
ll query(seg *now,ll ql,ll qr,ll l,ll r){
	if(ql<=l && qr>=r)return now->sum;
	else if(ql>r || qr<l)return 0;
	else return query(now->lc,ql,qr,l,mid)+query(now->rc,ql,qr,mid+1,r);
}
ll main(void){
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	for(ll u=0;u<T;u++){
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;i++)
			cin>>ar[i];
		t=build(1,n);
		for(ll i=0;i<m;i++){
			ll p,e,c;
			cin>>p>>e>>c;
			switch(p){
				case 0:
					SQRT(t,e,c,1,n);
					break;
				case 1:
					change(t,e,c,1,n);
					break;
				case 2:
					cout<<query(t,e,c,1,n)<<endl;
					break;
			}
		}
	}
	return 0;
}


