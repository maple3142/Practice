#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> edge;

const int MAX=1000005; 

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

vector<edge> E;
int main(void){
	ios::sync_with_stdio(false);
	int n,kase=0;
	while(cin>>n){
		if(kase++>0)cout<<endl;
		int a,b,c,sum=0;
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			sum+=c;
		}
		cout<<sum<<endl;
		
		int k,m;
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a>>b>>c;
			E.emplace_back(c,pii(a,b));
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			E.emplace_back(c,pii(a,b));
		}
		
		for(int i=1;i<=n;i++)par[i]=i;
		
		sort(E.begin(),E.end());
		int ans=0;
		for(edge e:E){
			if(find(e.second.first)!=find(e.second.second)){
				uni(e.second.first,e.second.second);
				ans+=e.first;
			}
		}
		cout<<ans<<endl;
		
		E.clear();
	}
	return 0;
}

