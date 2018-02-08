#include<iostream>
#define mid (l+r)/2
using namespace std;

const int NINF=-0x3f3f3f3f;
int max(int a,int b){
	return a>b?a:b;
}
int ar[200000+5];
struct tri{
	int l,r,v;
	tri(int l,int r,int v):l(l),r(r),v(v){
		
	}
};
struct seg{
	seg *lc,*rc;
	int sum=0;
	int mx=NINF;
	int mxl=-1,mxr=-1;
}*tree;
void pull(seg* t,int l,int r){
	t->sum=t->lc->sum+t->rc->sum;
	if( t->sum >= t->lc->mx && t->sum >= t->rc->mx ){ //t->sum = max
		t->mxl=l;
		t->mxr=r;
		t->mx=t->sum;
	}
	else if( t->lc->mx > t->sum && t->lc->mx > t->rc->mx ){ //t->lc->mx = max
		t->mxl=l;
		t->mxr=mid;
		t->mx=t->lc->mx;
	}
	else if( t->rc->mx >= t->sum && t->rc->mx >= t->lc->mx ){ //t->rc->mx = max
		t->mxl=mid+1;
		t->mxr=r;
		t->mx=t->rc->mx;
	}
}
seg* build(int l,int r){
	seg *t=new seg();
	if(l==r){
		t->sum=ar[l];
		t->mx=t->sum;
		t->mxl=t->mxr=l;
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	pull(t,l,r);
	return t;
}
tri query(seg *now,int ql,int qr,int l,int r){
	if(ql<=l && qr>=r)return tri(now->mxl,now->mxr,now->mx);
	else if(ql>r || qr<l)return tri(l,r,NINF);
	else{
		tri q1=query(now->lc,ql,qr,l,mid),q2=query(now->rc,ql,qr,mid+1,r);
		if(q1.v>q2.v){
			return q1;
		}
		else{
			return q2;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n,q;
	while(cin>>n>>q){
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		tree=build(1,n);
		int l,r;
		while(q--){
			cin>>l>>r;
			tri q=query(tree,l,r,1,n);
			cout<<q.l<<" "<<q.r<<" "<<q.v<<endl;
		}
	}
	return 0;
}

