#include<iostream>
#define mid ((l+r)/2)
typedef unsigned long long int ll;
using namespace std;

ll R,C,N;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
struct Seg1{
	Seg1* lc;
	Seg1* rc;
	ll val;
	ll tval,ty;
	Seg1(){
		lc=rc=NULL;
		tval=ty=val=0;
	}
};
struct Seg2{
	Seg2* lc;
	Seg2* rc;
	Seg1* tree;
	Seg2(){
		lc=rc=NULL;
		tree=NULL;
	}
}*t;
ll query1d(Seg1* id,ll y1,ll y2,ll l,ll r){
	if(!id)return 0;
	if(id->tval!=0){
		if(id->ty<=y2 && id->ty>=y1)
			return id->tval;
		return 0;
	}
	if(y1==l && y2==r)
		return id->val;
	if(y2<=mid)
		return query1d(id->lc,y1,y2,l,mid);
	if(y1>mid)
		return query1d(id->rc,y1,y2,mid+1,r);
	return gcd( query1d(id->lc,y1,mid,l,mid) , query1d(id->rc,mid+1,y2,mid+1,r) );
}
ll query2d(Seg2* id,ll x1,ll x2,ll y1,ll y2,ll l,ll r){
	if(!id)return 0;
	if(x1==l && x2==r)
		return query1d(id->tree,y1,y2,0,C-1);
	if(x2<=mid)
		return query2d(id->lc,x1,x2,y1,y2,l,mid);
	if(x1>mid)
		return query2d(id->rc,x1,x2,y1,y2,mid+1,r);
	return gcd( query2d(id->lc,x1,mid,y1,y2,l,mid) , query2d(id->rc,mid+1,x2,y1,y2,mid+1,r) );
}
void update1d(Seg1* id,ll y,ll val,ll l,ll r){
	if(l==r){
		id->val=val;
		return;
	}
	
	if(id->tval!=0){
		if(id->ty<=mid){
			if(!(id->lc))id->lc=new Seg1();
			update1d(id->lc,id->ty,id->tval,l,mid);
		}	
		if(id->ty>mid){
			if(!(id->rc))id->rc=new Seg1();
			update1d(id->rc,id->ty,id->tval,mid+1,r);
		}
		id->tval=id->ty=0;
		id->val=gcd( (!(id->lc)?0:id->lc->val) , (!(id->rc)?0:id->rc->val) );
	}
	else if(!(id->lc) && !(id->rc)){
		id->ty=y;
		id->tval=id->val=val;
		return;
	}
	if(y<=mid){
		if(!(id->lc))id->lc=new Seg1();
		update1d(id->lc,y,val,l,mid);
	}	
	if(y>mid){
		if(!(id->rc))id->rc=new Seg1();
		update1d(id->rc,y,val,mid+1,r);
	}
	id->val=gcd( (!(id->lc)?0:id->lc->val) , (!(id->rc)?0:id->rc->val) );
}
void update2d(Seg2* id,ll x,ll y,ll val,ll l,ll r){
	if(l==r){
		if(!(id->tree))id->tree=new Seg1();
		update1d(id->tree,y,val,0,C-1);
		return;
	}
	if(x<=mid){
		if(!(id->lc))id->lc=new Seg2();
		update2d(id->lc,x,y,val,l,mid);
	}
	if(x>mid){
		if(!(id->rc))id->rc=new Seg2();
		update2d(id->rc,x,y,val,mid+1,r);
	}
	ll qlc=(!(id->lc)?0:query1d(id->lc->tree,y,y,0,C-1));
	ll qrc=(!(id->rc)?0:query1d(id->rc->tree,y,y,0,C-1));
	if(!id->tree)id->tree=new Seg1();
	update1d(id->tree,y, gcd(qlc,qrc) ,0,C-1);
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>R>>C>>N){
		t=new Seg2();
		for(ll u=0;u<N;u++){
			ll act;
			cin>>act;
			if(act==1){
				ll P,Q,K;
				cin>>P>>Q>>K;
				update2d(t,P,Q,K,0,R-1);
			}
			if(act==2){
				ll P,Q,U,V;
				cin>>P>>Q>>U>>V;
				cout<<query2d(t,P,U,Q,V,0,R-1)<<endl;
			}
		}
	}
	return 0;
}


