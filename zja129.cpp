#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX=100000;

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

int par[MX];
inline int find(int a){
	return par[a]=(a!=par[a]?find(par[a]):a);
}
inline int uni(int a,int b){
	par[find(a)]=par[find(b)];
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int a,b,c;
		while(m--){
			cin>>a>>b>>c;
			edges.emplace_back(a,b,c);
		}
		for(int i=0;i<n;i++)par[i]=i;
		sort(edges.begin(),edges.end());
		long long int ans=0;
		for(Edge e:edges){
			if(find(e.a)!=find(e.b)){
				uni(e.a,e.b);
				ans+=e.c;
			}
		}
		bool lianton=true;
		for(int i=1;i<n;i++)if(find(0)!=find(i))lianton=false;
		cout<<(lianton?ans:-1)<<endl;
		edges.clear();
	}
	return 0;
}

