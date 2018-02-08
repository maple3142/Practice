#include<iostream>
#define mid ((l+r)/2)
using namespace std;

const int INF=0x3f3f3f3f;
int ar[1000005];
struct seg{
	seg *lc,*rc;
	int mn;//min
	seg(){
		mn=INF;
	}
}*tree;
void pull(seg *t){
	t->mn=min(t->rc->mn,t->lc->mn);
}
seg* build(int l,int r){
	seg *t=new seg();
	if(l==r){
		t->mn=ar[l];
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	pull(t);
	return t;
}
void change(seg *now,int pos,int val,int l,int r){
	if(l==r){
		now->mn=val;
		return;
	}
	if(pos<=mid)
		change(now->lc,pos,val,l,mid);
	else
		change(now->rc,pos,val,mid+1,r);
	pull(now);
}
int query(seg *now,int ql,int qr,int l,int r){
	if(ql>r || qr<l)return INF;
	else if(ql<=l && qr>=r)return now->mn;
	else return min( query(now->lc,ql,qr,l,mid) , query(now->rc,ql,qr,mid+1,r) );
}
int main(void){
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T>>n;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	tree=build(0,n-1);
	while(T--){//queries
		int a,x,y;
		cin>>a>>x>>y;
		if(a==1){//min[x,y]
			cout<<query(tree,x,y,0,n-1)<<endl;
		}
		else{//ar[x]=y
			change(tree,x,y,0,n-1);
		}
	}
	return 0;
}

