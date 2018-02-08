#include<iostream>
#define mid ((l+r)/2)
using namespace std;
typedef long long int ll;

int ar[100005];
struct seg{
	seg *lc,*rc;
	ll mx,lmx,rmx,sum;
	seg(){
		mx=lmx=rmx=sum=0;
	}
}*tree;
struct tri{
	ll lmx,rmx,mx,sum;
	tri(){
		mx=lmx=rmx=sum=0;
	}
	tri(ll a,ll b,ll c,ll d){
		lmx=a;
		rmx=b;
		mx=c;
		sum=d;
	}
	tri(seg* t){
		lmx=t->lmx;
		rmx=t->rmx;
		mx=t->mx;
		sum=t->sum;
	}
};
void pull(seg* t){
	t->sum=t->lc->sum+t->rc->sum;
	t->lmx=max(t->rc->lmx+t->lc->sum,t->lc->lmx);
	t->rmx=max(t->rc->rmx,t->lc->rmx+t->rc->sum);
	t->mx=max( max( t->lc->mx , t->rc->mx ) , t->lc->rmx+t->rc->lmx );
}
seg* build(int l,int r){
	seg *t=new seg();
	if(l==r){
		t->mx=t->lmx=t->rmx=t->sum=ar[l];
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	pull(t);
	return t;
}
tri query(seg *now,int ql,int qr,int l,int r){
	if(ql>r || qr<l)return 0;
	else if(ql==l && qr==r) return tri(now);
	else{
		if(qr<=mid){
			return query(now->lc,ql,qr,l,mid);
		}
		else if(ql>mid){
			return query(now->rc,ql,qr, mid+1,r);
		}
		else{
			tri lll=query(now->lc,ql,mid,l,mid);
			tri rrr=query(now->rc,mid+1,qr,mid+1,r);
			ll mx=max( max(lll.mx,rrr.mx) , lll.rmx+rrr.lmx);
			ll lmx=max(lll.lmx,lll.sum+rrr.lmx);
			ll rmx=max(rrr.rmx,rrr.sum+lll.rmx);
			ll sum=lll.sum+rrr.sum;
			return tri( lmx , rmx , mx , sum);
		}
		
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>ar[i];
	tree=build(1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		ll x=query(tree,l,r,1,n).mx;
		cout<<(x>=0?x:0)<<endl;
	}
	return 0;
}

