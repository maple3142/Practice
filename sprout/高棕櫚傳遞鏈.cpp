#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX=1000001;
vector<int> to[MX];
vector<int> r;
int lv[MX];
bool vis[MX];
int sc=0,root;
int dfs(int now,int deep,int par){
	vis[now]=true;
	int low=lv[now]=deep;
	for(int i=0;i<to[now].size();i++){
		int p=to[now][i];
		int x;
		if(vis[p]){if(p!=par)low=min(low,lv[p]);}
		else{
			x=dfs(p,deep+1,now);
			if(x>=deep){
				if(deep==0)sc++;
				else r.push_back(now);
			}
			low=min(low,x);
		}
	}
	return low;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	for(root=1;root<=n;root++){
		if(!vis[root]){
			dfs(root,0,-1);
			if(sc>1)r.push_back(root);
			sc=0;
		}
	}
	sort(r.begin(),r.end());
	for(int s:r){
		cout<<s<<endl;
	}
	return 0;
}

