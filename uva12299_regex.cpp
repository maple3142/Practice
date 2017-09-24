#include<iostream>
#include<vector>
#include<regex>
#include<deque>
#define mid (l+r)/2
#define lc id*2
#define rc id*2+1
using namespace std;

int n,q;
int ar[100000+5];
int tree[4*100000+5];
void build(int id,int l,int r){
	if(l==r){
		tree[id]=ar[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[id]=min(tree[lc],tree[rc]);
}
void set(int id,int pos,int val,int l,int r){
	if(l==r){
		tree[id]=val;
		return;
	}
	if(pos<=mid){
		set(lc,pos,val,l,mid);
	}
	else{
		set(rc,pos,val,mid+1,r);
	}
	tree[id]=min(tree[lc],tree[rc]);
}
int query(int id,int l,int r,int ql,int qr){
	if(ql==l&&qr==r)return tree[id];
	if(ql>mid){
		return query(rc,mid+1,r,ql,qr);
	}
	else if(qr<=mid){
		return query(lc,l,mid,ql,qr);
	}
	else{
		return min( query(lc,l,mid,ql,mid) , query(rc,mid+1,r,mid+1,qr) );
	}
}
void shift(vector<int> v){
	deque<int> dq;
	for(int pos:v){
		dq.push_back(query(1,1,n,pos,pos));
	}
	dq.push_back(dq.front());
	dq.pop_front();
	for(int pos:v){
		set(1,pos,dq.front(),1,n);
		dq.pop_front();
	}
}
int main(void){
	ios::sync_with_stdio(false);
	regex reg("\\d+");
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>ar[i];
	build(1,1,n);
	while(q--){
		string s,ss;
		cin>>s;
		ss=s;
		vector<int> v;
		smatch sm;
		while(regex_search(s, sm, reg)){
			v.push_back(stoi(sm[0]));
			s=sm.suffix().str();
		}
		if(ss[0]=='q'){
			cout<<query(1,1,n,v[0],v[1])<<endl;
		}
		else{
			shift(v);
		}
	}
	return 0;
}

