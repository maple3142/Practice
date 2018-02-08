#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,pii> edge;

const int MAX=755; 

int sz[MAX];
int par[MAX];
int find(int x){
	return par[x]=(par[x]==x?x:find(par[x]));
}
void uni(int a,int b){
	if(sz[find(a)]>sz[find(b)]){
		par[find(b)]=find(a);
		sz[a]+=sz[b];
		sz[b]=0;
	}
	else{
		par[find(a)]=find(b);
		sz[b]+=sz[a];
		sz[a]=0;
	}
}

inline double dis(pii a,pii b){
	int x=a.first-b.first;
	int y=a.second-b.second;
	return sqrt(x*x+y*y);
}

pii B[MAX];
vector<int> to[MAX];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)par[i]=i;
		
		int a,b;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			B[i]=pii(a,b);
		}
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			uni(a,b);
		}
		
		vector<edge> edges;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(find(i)==find(j))continue;
				edges.push_back(edge(dis(B[i],B[j]),pii(i,j)));
			}
		}
		double sum=0;
		sort(edges.begin(),edges.end());
		for(edge e:edges){
			if(find(e.second.first)!=find(e.second.second)){
				uni(e.second.first,e.second.second);
				sum+=e.first;
			}
		}
		cout<<fixed<<setprecision(2)<<sum<<endl;
		
		memset(to,0,sizeof(to));
	}
	return 0;
}

