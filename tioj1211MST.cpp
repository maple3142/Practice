#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
	int l,r;
	int w;
	edge(){
		
	}
	edge(int a,int b,int c){
		l=a;
		r=b;
		w=c;
	}
};
bool comp(edge a,edge b){
	return a.w<b.w;
}
edge g[1000005];
int par[10005];
int find(int a){
	if(a==par[a])return a;
	else{
		par[a]=find(par[a]);
		return par[a];
	}
}
void uni(int a,int b){//a in b
	par[find(a)]=find(b);
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		if(n==m && n==0)break;
		for(int u=0;u<m;u++){
			int i,j,c;
			cin>>i>>j>>c;
			g[u]=edge(i,j,c);
		}
		for(int i=1;i<=n;i++)
			par[i]=i;
		sort(g,g+m,comp);
		long long int sum=0,uc=0;
		for(int u=0;u<m;u++){
			if(find(g[u].l) == find(g[u].r))continue;
			else{
				uni(g[u].l,g[u].r);
				sum+=g[u].w;
				uc++;
			}
		}
		if(uc<n-1)cout<<-1<<endl;
		else cout<<sum<<endl;
	}
	return 0;
}


