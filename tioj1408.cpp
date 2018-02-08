#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> range;

vector<range> v;
struct seg{
	seg *lc,*rc;
	int val=0;
};
seg* build(int l,int r){
	seg* t=new seg();
	if(l==r)return t;
	int mid=(l+r)/2;
	t->lc=build(l,mid);
	t->rc=build(mid+1,r);
	return t;
}
void pull(seg* t){
	t->val=t->lc->val+t->rc->val;
}
void set(seg* t,int l,int r,int ql,int qr){
	if(ql>r||qr<l)return;
	if(ql<=l&&qr>=r){
		t->val=r-l+1;
		return;
	}
	int mid=(l+r)/2;
	set(t->lc,l,mid,ql,qr);
	set(t->rc,mid+1,r,ql,qr);
	pull(t);
}
int search(seg* t,int l,int r,int ql,int qr){
	int mid=(l+r)/2;
	if(ql>r||qr<l)return 0;
	else if(ql<=l&&qr>=r)return t->val;
	else{
		if(t->val==r-l+1){//all is 1
			if(qr<r)return qr-l+1;
			else return r-ql+1;
		}
		return search(t->lc,l,mid,ql,qr)+search(t->rc,mid+1,r,ql,qr);
	}
}
void deltree(seg *t,int l,int r){
	if(l==r){
		delete t;
		return;
	}
	int mid=(l+r)/2;
	deltree(t->lc,l,mid);
	deltree(t->rc,mid+1,r);
	delete t;
	return;
} 
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		int a,b,c,x,sum=0;
		while(n--){
			cin>>a>>b>>c;
			v.push_back(range(pii(a,b-1),c));
			x=max(x,b-1);
		}
		sort(v.begin(),v.end(),[](range a,range b){
			return a.X.Y<b.X.Y; 
		});
		
		seg *t=build(0,x);
		range f=v[0];
		set(t,0,x,f.X.Y-f.Y+1,f.X.Y);//b-c+1 to b
		sum+=f.Y;
		//cout<<search(t,0,x,f.X.Y-f.Y,f.X.Y)<<endl;
		for(int i=1;i<v.size();i++){
			if(v[i].X.X<=v[i-1].X.Y){
				int need=v[i].Y-search(t,0,x,v[i].X.X,v[i-1].X.Y); //now.c-(now.a to prev.b)
				//cout<<need<<endl;
				if(need<=0)continue;
				set(t,0,x,v[i].X.Y-need+1,v[i].X.Y); //now.b-need to now.b
				sum+=need;
			}
			else{
				set(t,0,x,v[i].X.Y-v[i].Y+1,v[i].X.Y);
				sum+=v[i].Y;
				//cout<<v[i].Y<<endl;
			}
		}
		cout<<sum<<endl;
		v.clear();
		deltree(t,0,x);
	}
	return 0;
}

