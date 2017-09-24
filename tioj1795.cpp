#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
	int a,b,w;
}E[300010];
class djs{
	int par[100005];
	public:
		djs(int n){
			for(int i=0;i<=n;i++)
				par[i]=i;
		} 
		int find(int x){return (x==par[x]?x:par[x]=find(par[x]));}
		void uni(int x,int y){par[find(x)]=find(y);}
		bool same(edge e){return find(e.a)==find(e.b);}
		void uni(edge e){uni(e.a,e.b);}
};
int main(void){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		E[i]=((edge){u,v,c});
	}
	
	sort(E,E+m,[](const edge &a,const edge &b){
		return a.w<b.w;
	});
	int k1=0;
	djs s(n);
	for(int i=0;i<m;i++){
		edge e=E[i];
		if(!s.same(e)){
			s.uni(e);
			k1+=e.w;
		}
	}
	
	sort(E,E+m,[](const edge &a,const edge &b){
		return a.w>b.w;
	});
	int k2=0;
	djs ss(n);
	for(int i=0;i<m;i++){
		edge e=E[i];
		if(!ss.same(e)){
			ss.uni(e);
			k2+=e.w;
		}
	}
	
	if(k1<=k && k<=k2)cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
	return 0;
}

