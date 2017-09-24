#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;
const ll INF=2147483648;
struct node{
	int size,pri;
	node* lc,*rc;
	ll max,min;
	ll val;
	node(int v=0){
		val=v;
		max=0;
		min=INF;
		size=1;
		lc=rc=NULL;
		pri=rand();
	}
}*T;
ll max(ll a,ll b){
	return a>b?a:b;
}
ll min(ll a,ll b){
	return a<b?a:b;
}
int getSize(node *s){
	if(!s)return 0;
	return s->size;
}
ll getMax(node *s){
	if(!s)return 0;
	return s->max;
}
ll getMin(node *s){
	if(!s)return INF;
	return s->min;
}
void pull(node *t){
	t->max=max(getMax(t->lc),getMax(t->rc));
	t->max=max(t->max,t->val);
	t->min=min(getMin(t->lc),getMin(t->rc));
	t->min=min(t->min,t->val);
	t->size=getSize(t->lc)+getSize(t->rc)+1;
}
node* merge(node* a,node* b){
	if(!a)return b;
	if(!b)return a;
	if(a->pri>b->pri){
		a->rc=merge(a->rc,b);
		pull(a);
		return a;
	}
	else{
		b->lc=merge(a,b->lc);
		pull(b);
		return b;
	}
}
void split(node* s,int k,node*& a,node*& b){
	if(!s)a=b=NULL;
	else if(getSize(s->lc)<k){
		a=s;
		split(s->rc,k-getSize(s->lc)-1,a->rc,b);
		pull(a);
	}
	else{
		b=s;
		split(s->lc,k,a,b->lc);
		pull(b);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	T=NULL;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		T=merge(T,new node(y));	
	}
	for(int u=0;u<m;u++){
		int i,j;
		cin>>i>>j;
		node* a,*b,*c;
		split(T,i-1,a,b);
		split(b,j-i+1,b,c);
		cout<<b->max-b->min<<endl;
		T=merge(merge(a,b),c);
	}
	return 0;
}

