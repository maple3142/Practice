#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG

//#define deb(...) do{fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_out(__VA_ARGS__);}while(0);
//template<typename T>               void _out(T &&x){cerr<<x<<endl;}
//template<typename T, typename...S> void _out(T &&x, S &&...y){cerr<<x<<", ";_out(y...)}
//template<typename T, typename S>   ostream& operator << (ostream &os, const pair<T, S> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
//template<typename It>              ostream& _out_it(ostream &os, It ita, It itb)
//{
//	os<<"{"; for(It it=ita;it!=itb;++it) os<<(it==ita?"":", ")<<*itl;os<<"}";
//	return os;
//}
//template<typename T, typename S>   ostream& operator << (ostream &os, const map<T, S>  &m){return _out_it(os,m.begin(),m.end());}
//template<typename T, typename S>   ostream& operator << (ostream &os, const map<T, S>  &m){return _out_it(os,m.begin(),m.end());}
//template<typename T, typename S>   ostream& operator << (ostream &os, const map<T, S>  &m){return _out_it(os,m.begin(),m.end());}

#define INITIO() cout<<setprecision(numeric_limits<double>::max_digits10+1);
#else
#define deb(...)
#define debit(...)
#define endl '\n'
#define INITIO() ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(numeric_limits<double>::max_digits10+1);
#endif
#define X first
#define Y second
typedef long long ll;
const ll inf=0x3f3f3f3f;
const int maxn=1e5+10;
ll N,Q,C,P,a[maxn];
ll powmod(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans*=a, ans%=P;
		a*=a;
		a%=P;
		b>>=1;
	}
	return ans;
}
struct seg_1d{
	ll st[maxn*4],lazy[maxn*4];
	void up(int i) {
		st[i]=(st[i*2]+st[i*2+1])%P;
	}
	void bd(int l,int r,int i=1) {
		if(l==r) {
			st[i]=a[l];
			return;
		}
		int mid=(l+r)/2;
		bd(l,mid,i*2);
		bd(mid+1,r,i*2+1);
		up(i);
	}
	ll qry(int l,int r,int i=1) {
		if(r<p||p<l) return 0;
		if(l==p&&p==r) return st[i];
		int mid=(l+r)/2;
		return (qry(l,mid,i*2)+qry(mid+1,r,i*2+1))%P;
	}
	void chg(int l,int r,int i=1) {
		if(r<p||p<l) return;
		if(l==p&&p==r) {st[i]=v; return;}
		int mid=(l+r)/2;
		chg(l,mid,i*2);
		chg(mid+1,r,i*2+1);
		up(i);
	}
	void rpl(int l,int r,int p,ll v,int i=1) {
		if(r<p||p<l) return;
		if(l==p&&p==r) {st[i]=v; return;}
		int mid=(l+r)/2;
		rpl(l,mid,i*2);
		rpl(mid+1,r,i*2+1);
		up(i);
	}
};
		
int main(){
	INITIO()
	cin>>N>>Q>>C>>P;
	for(int i=0;i<N;++i) cin>>a[i];
	
	return 0;
}


