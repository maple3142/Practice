#include<iostream>
#define mid ((l+r)/2)
using namespace std;
typedef long long int ll;

const int INF=0x3f3f3f3f;
int ar[1000005];
struct seg{
	seg *lc,*rc;
	ll mx,chg;
	seg(){
		mx=0;
		chg=0;
	}
}*tree;
seg* build(int l,int r){
	seg *t=new seg();
	if(l==r){
		t->mx=ar[l];
		return t;
	}
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	t->mx=max(t->rc->mx,t->lc->mx);
	return t;
}
void add(seg *now,int al,int ar,int val,int l,int r){//[al,ar]+val
	if(r<al || l>ar)return;
	if(al<=l && r<=ar)now->chg+=val;
	else{
		add(now->lc,al,ar,val,l,mid);
		add(now->rc,al,ar,val,mid+1,r);
		now->mx=max(now->lc->mx+now->lc->chg,now->rc->mx+now->rc->chg);
	}
}
ll query(seg *now,int ql,int qr,int l,int r){
	if(ql>r || qr<l)return 0;
	else if(ql<=l && qr>=r)return now->mx;
	else{
		if(now->chg){
			add(now->lc,l,mid,now->chg,l,mid);
			add(now->rc,mid+1,r,now->chg,mid+1,r);
			now->chg=0;
		}
		return max( query(now->lc,ql,qr,l,mid) , query(now->rc,ql,qr,mid+1,r) );
	} 
}
int main(void){
	ios::sync_with_stdio(false);
	int T,n;
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	tree=build(1,n);
	while(T--){//queries
		int a;
		cin>>a;
		if(a==1){//range add
			int x,y,v;
			cin>>x>>y>>v;
			add(tree,x,y,v,1,n);
		}
		else{//query
			int x,y;
			cin>>x>>y;
			cout<<query(tree,x,y,1,n)<<endl;
		}
	}
	return 0;
}

