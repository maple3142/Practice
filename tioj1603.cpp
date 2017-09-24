#include<iostream>
#define mid (l+r)/2
#define lc id*2
#define rc id*2+1
using namespace std;

struct node{
	unsigned int max,min;
	node(){
		
	}
	node(unsigned int a,unsigned int b){
		max=a;
		min=b;
	}
};
unsigned int ar[100000+5];
node tree[5*100000+5];
void build(unsigned int id,unsigned int l,unsigned int r){
	if(l==r){
		tree[id].max=ar[l];
		tree[id].min=ar[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[id].min=min(tree[lc].min,tree[rc].min);
	tree[id].max=max(tree[lc].max,tree[rc].max);
}
node q(unsigned int id,unsigned int l,unsigned int r,unsigned int ql,unsigned int qr){
	if(ql==l&&qr==r)return tree[id];
	if(ql>mid){
		return q(rc,mid+1,r,ql,qr);
	}
	else if(qr<=mid){
		return q(lc,l,mid,ql,qr);
	}
	else{
		node lnode=q(lc,l,mid,ql,mid);
		node rnode=q(rc,mid+1,r,mid+1,qr);
		return node(max( lnode.max , rnode.max ),min( lnode.min , rnode.min ));
	}
}
int main(void){
	cin.sync_with_stdio(false);
	unsigned int n,m;
	while(cin>>n>>m){
		for(unsigned int i=1;i<=n;i++){
			cin>>ar[i];
		}
		build(1,1,n);
		for(unsigned int i=0;i<m;i++){
			unsigned int x,y;
			cin>>x>>y;
			node no=q(1,1,n,x,y);
			cout<<no.max-no.min<<endl;
		}
	}
	return 0;
}


