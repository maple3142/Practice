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

int main(){
	INITIO()
	ll N,M;
	cin>>N>>M;
	if(M==(N*(N-1)>>1)) {
		puts("0");
	} else cout<<N<<endl;
	return 0;
}



