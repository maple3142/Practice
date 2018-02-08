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

typedef pair<int,int> pii;
vector<int> to[2005];

int bfs(int start){
	bool vis[2005];
	memset(vis,0,sizeof(vis));
	
	int sum=1;
	queue<pii> q;
	q.push(pii(start,1));
	vis[start]=true;
	while(!q.empty()){
		pii now=q.front();
		q.pop();
		
		sum*=now.second;
		
		int cnt=0;
		for(int p:to[now.first]){
			if(vis[p])continue;
			cnt++;
		}
		for(int p:to[now.first]){
			if(vis[p])continue;
			q.push(pii(p,cnt));
			vis[p]=true;
		}
	}
	return sum;
	
}
int main(){
	INITIO()
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	int s=0;
	for(int i=1;i<=n;i++){
		s+=bfs(i);
		cout<<i<<" "<<bfs(i)<<endl;
	}
	cout<<s<<endl;
	
	return 0;
}



