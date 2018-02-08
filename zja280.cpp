#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,k;
vector<int> ar[101];
bool vis[101];
bool dfs(int now){
	vis[now]=true;
	if(now==n){
		return true;
	}
	for(int p:ar[now]){
		if(!vis[p]){
			bool r=dfs(p);
			if(r)return true;
		}
	}
	return false;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>k){
		int a,b;
		while(k--){
			cin>>a>>b;
			ar[a].push_back(b);
		}
		if(dfs(0)){
			cout<<"Ok!"<<endl;
		}
		else{
			cout<<"Impossib1e!"<<endl;
		}
		memset(ar,0,sizeof(ar));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

