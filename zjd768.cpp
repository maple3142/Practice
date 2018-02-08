#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> to[200];
bool vis[200];
bool color[200];
bool bicolorable=true;
void dfs(int now,bool clr){
	color[now]=clr;
	vis[now]=true;
	for(int p:to[now]){
		if(vis[p]&&color[p]==clr){
			bicolorable=false;
			return;
		}
		if(!vis[p])dfs(p,!clr);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n){
		if(n==0)break;
		cin>>m;
		int a,b;
		while(m--){
			cin>>a>>b;
			to[a].push_back(b);
			to[b].push_back(a);
		}
		bicolorable=true;
		dfs(0,0);
		if(!bicolorable){
			cout<<"NOT ";
		}
		cout<<"BICOLORABLE."<<endl;
		
		memset(to,0,sizeof(to));
		memset(vis,0,sizeof(vis));
		memset(color,0,sizeof(color));
	}
	return 0;
}

