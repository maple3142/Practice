#include<iostream>
#define mid (l+r)/2
#define lc id*2
#define rc id*2+1
using namespace std;

struct node{
	int val,add;
	node(){
		
	}
	node(int a){
		val=a;
		add=0;
	}
};
int ar[100000+5];
node tree[4*100000+5];
void build(int id,int l,int r){
	if(l==r){
		tree[id]=node(ar[l]);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[id]=node(tree[lc].val+tree[rc].val);
}
void add(int id,int l,int r,int ql,int qr,int val){
	if(l==ql && r==qr){
		tree[id].val+=val*(r-l+1);
		tree[id].add+=val;
		return;
	}
	tree[lc].add+=tree[id].add;
	tree[lc].val+=tree[id].add*(mid-l+1);
	tree[rc].add+=tree[id].add;
	tree[rc].val+=tree[id].add*(r-mid);
	tree[id].add=0;
	if(qr<=mid){
		add(lc,l,mid,ql,qr,val);
	}
	else if(ql>mid){
		add(rc,mid+1,r,ql,qr,val);
	}
	else{
		add(lc,l,mid,ql,mid,val);
		add(rc,mid+1,r,mid+1,qr,val);
	}
	tree[id].val= tree[lc].val+tree[rc].val;
}
int query(int id,int l,int r,int ql,int qr){
	if(l==ql && r==qr){
		return tree[id].val;
	}
	tree[lc].add+=tree[id].add;
	tree[lc].val+=tree[id].add*(mid-l+1);
	tree[rc].add+=tree[id].add;
	tree[rc].val+=tree[id].add*(r-mid);
	tree[id].add=0;

	if(qr<=mid){
		return query(lc,l,mid,ql,qr);
	}
	else if(ql>mid){
		return query(rc,mid+1,r,ql,qr);
	}
	else{
		return query(lc,l,mid,ql,mid)+query(rc,mid+1,r,mid+1,qr);
	}
}
int main(void){
	cin.sync_with_stdio(false);
	int T;
	cin>>T;
	for(int u=0;u<T;u++){
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		build(1,1,n);
		for(int i=0;i<q;i++){
			string cmd;
			cin>>cmd;
			if(cmd=="add"){
				int l,r,d;
				cin>>l>>r>>d;
				add(1,1,n,l,r,d);
			}
			else{
				int l,r;
				cin>>l>>r;
				cout<<query(1,1,n,l,r)<<endl;
			}
		}
	}
	return 0;
}


