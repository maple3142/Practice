#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int par[1000001];
int find(int a){
	return par[a]=(par[a]==a?a:find(par[a]));
}
void uni(int a,int b){
	par[find(a)]=find(b);
}
struct edge{
	int a,b;
	int dis;
	edge(int x,int y,int z){
		a=x;
		b=y;
		dis=z;
	}
};
int main(void){
	ios::sync_with_stdio(false);
	bool first=true;
	int n;
	while(cin>>n){
		if(!first)cout<<endl;
		first=false;
		vector<edge> E;
		for(int i=1;i<=n;i++)
			par[i]=i;
		int sum=0;
		for(int i=1;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			sum+=c;
		}
		cout<<sum<<endl;
		int k,m;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,b,c;
			cin>>a>>b>>c;
			E.emplace_back(a,b,c);
		}
		cin>>m;
		for(int i=1;i<=m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			E.emplace_back(a,b,c);
		}
		int l=m+k;
		sort(E.begin(),E.end(),[](edge a,edge b){
			return a.dis<b.dis;
		});
		int le=0;
		for(edge e:E){
			if(find(e.a)!=find(e.b)){
				uni(e.a,e.b);
				le+=e.dis;
			}
		}
		cout<<le<<endl;
	}
	return 0;
}

