#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;

int n,m;
struct edge{
	ll a,b,w;
	edge(int x,int y,ll z){
		a=x;
		b=y;
		w=z;
	}
};
vector<edge> ve;
class djs{
	int par[1005];
	public:
		djs(){
			for(int i=0;i<=n;i++)
				par[i]=i;
		} 
		int find(int x){return (x==par[x]?x:par[x]=find(par[x]));}
		void uni(int x,int y){par[find(x)]=find(y);}
		bool same(edge e){return find(e.a)==find(e.b);}
		void uni(edge e){uni(e.a,e.b);}
};
ll kruskal(vector<edge> v){
	djs s;
	ll sum=0,c=0;
	for(edge e:v){
		if(!s.same(e)){
			s.uni(e);
			sum+=e.w;
			c++;
		}
		if(c>=n)break;
	}
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		if(a==b)continue;
		ve.emplace_back(a,b,w);
	}
	sort(ve.begin(),ve.end(),[](const edge &a,const edge &b){
		return a.w<b.w;
	});
	ll mn=kruskal(ve);
	ll smn=0x3f3f3f3f;
	for(int i=0;i<ve.size()-1;i++){
		swap(ve[i],ve[i+1]);
		ll r=kruskal(ve);
		if(r!=mn){
			smn=min(smn,r);
		}
		swap(ve[i],ve[i+1]);
	}
	cout<<mn<<" "<<smn<<endl;
	return 0;
}

