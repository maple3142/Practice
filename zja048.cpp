#include<iostream>
using namespace std;

struct seg{
	seg *lc,*rc;
	int val=1;
};
inline void pull(seg *t){
	t->val=t->lc->val*t->rc->val;
}
seg* build(int l,int r){
	seg *t=new seg();
	if(l==r)return t;
	int mid=(l+r)/2;
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	return t;
}
void change(seg *t,int l,int r,int pos){
	if(l==r){
		if(t->val==1)t->val=-1;
		else t->val=1;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)change(t->lc,l,mid,pos);
	else change(t->rc,mid+1,r,pos);
	pull(t);
}
int query(seg *t,int l,int r,int ql,int qr){
	int mid=(l+r)/2;
	if(ql<=l && qr>=r)return t->val;
	else if(ql>r || qr<l)return 1;
	else return query(t->lc,l,mid,ql,qr)*query(t->rc,mid+1,r,ql,qr);
}
int main(void){
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	seg *root=build(1,n);
	int v,l,r;
	while(q--){
		cin>>v;
		if(v==1){
			cin>>v;
			change(root,1,n,v);
		}
		else{
			cin>>l>>r;
			if(query(root,1,n,l,r)==1)cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
