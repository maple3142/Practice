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
const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
ll ans=-(0x3f3f3f3f3f3f3f3f),N,a[maxn],psum,nsum;
vector<pair<ll,ll>> as;
ll pcnt;
int main(){
	INITIO()
	cin>>N;
	for(int i=0;i<N;++i) {
		cin>>a[i];
		as.push_back({a[i],i});
		if(a[i]>=0) ++pcnt;
	}
	sort(as.begin(),as.end());
	if(pcnt>1) {
		ll j=-1,k=0;
		for(int i=0;i<N;++i) {
			if(a[i]>=0) {
				if(j<0) j=i;
				k=i;
				psum+=a[i];
			}
		}
		if(k-j+1==pcnt) {
			if(pcnt>2) {
				ll m=inf;
				for(int i=j+1;i<k;++i) m=min(m,a[i]);
				ans=max(ans,psum-m);
				if(j-1>=0) ans=max(ans,psum-a[j]+a[j-1]);
				if(k+1<N) ans=max(ans,psum-a[k]+a[k+1]);
				for(int i=0;i<N;++i) if(i!=j-1&&a[i]<0&&i!=k+1) ans=max(ans,psum+a[i]);
			} else {
	//			cout<<ans<<endl;
				for(int i=0;i<N;++i) if(i!=j-1&&i!=j+1&&i!=j) ans=max(ans,a[j]+a[i]);
				for(int i=0;i<N;++i) if(i!=k-1&&i!=k+1&&i!=k) ans=max(ans,a[k]+a[i]);
			}
		} else {
			ans=psum;
		}
	} else if(pcnt==1) {
		ll j=0,M=-inf,ans1;
		for(int i=0;i<N;++i) if(a[i]>=0) {ans1=a[i];j=i;break;}
		for(int i=0;i<N;++i) {
			if(i!=j-1&&i!=j&&i!=j+1) M=max(M,a[i]);
		}
		if(M==-inf) ans1==-inf;
		else ans1+=M;
		ans=max(ans1,a[j-1]+a[j+1]);
	} else {
		reverse(as.begin(),as.end());
		for(int i=1;i<N;++i) {
			if(as[0].Y!=as[i].Y+1&&as[0].Y!=as[i].Y-1) ans=max(ans,as[0].X+as[i].X);
		}
		for(int i=2;i<N;++i) {
			if(as[1].Y!=as[i].Y+1&&as[1].Y!=as[i].Y-1) ans=max(ans,as[1].X+as[i].X);
		}
		for(int i=3;i<N;++i) {
			if(as[2].Y!=as[i].Y+1&&as[2].Y!=as[i].Y-1) ans=max(ans,as[2].X+as[i].X);
		}
//		for(int i=N-2;i>=0;--i) {
//			if((as.back().Y!=as[i].Y+1)&&(as.back().Y!=as[i].Y-1)) {ans=max(ans,as.back().X+as[i].X);}
//		}
//		for(int i=N-1;i>=0;--i) {
//			if((as[as.size()-2].Y!=as[i].Y+1)&&(as[as.size()-2].Y!=as[i].Y-1)&&i!=as.size()-2) {ans=max(ans,as[as.size()-2].X+as[i].X);}
//		}
	}
	cout<<ans<<endl;
	return 0;
}



