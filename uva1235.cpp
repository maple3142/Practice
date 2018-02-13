#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX=501;

inline int abs(int a){
	return a>0?a:-a;
}
inline int dis(int a,int b){
	int roll=0,tmp;
	for(int i=1;i<=4;i++){
		tmp=abs(a%10-b%10);
		roll+=min(tmp,10-tmp);
		a/=10;
		b/=10;
	}
	return roll;
}
struct Edge{
	int a,b,c;
	Edge(int d,int e,int f){
		a=d;
		b=e;
		c=f;
	}
	bool operator<(const Edge& e){
		return c<e.c;
	}
};
vector<Edge> edges;
int ar[MX];
int par[MX];
inline int find(int a){
	return par[a]=(a!=par[a]?find(par[a]):a);
}
inline int uni(int a,int b){
	par[find(a)]=par[find(b)];
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			par[i]=i;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				edges.emplace_back(i,j,dis(ar[i],ar[j]));
		sort(edges.begin(),edges.end());
		int ans=0;
		for(Edge x:edges){
			if(find(x.a)!=find(x.b)){
				uni(x.a,x.b);
				ans+=x.c;
			}
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++)mn=min(mn,dis(0,ar[i]));
		cout<<ans+mn<<endl;
		edges.clear();
	}
	return 0;
}

