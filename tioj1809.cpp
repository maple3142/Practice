#include<iostream>
#include<utility>
#include<unordered_map>
using namespace std;
typedef pair<int,int> pii;

struct pairhash {
	public:
		template <typename T, typename U>
		int operator()(const pair<T, U> &x) const{
			return hash<T>()(x.first) ^ hash<U>()(x.second);
		}
};
unordered_map<pii,bool,pairhash> M;
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,q;
	cin>>n>>m>>q;
	int a,b;
	while(m--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		M[pii(a,b)]=true;
	}
	while(q--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		cout<<(M[pii(a,b)]?"yes\n":"no\n");
	}
	cout.flush();
	return 0;
}

