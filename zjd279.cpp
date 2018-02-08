#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> to[101];
bool vis[101];
void dfs(int now){
	for(int p:to[now]){
		if(!vis[p]){
			vis[p]=true;
			dfs(p);
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(true){
		cin>>n;
		if(n==0)break;
		int s;
		while(true){
			cin>>s;
			if(s==0)break;
			int x;
			while(true){
				cin>>x;
				if(x==0)break;
				to[s].push_back(x);
			}
		}
		int T,q;
		cin>>T;
		while(T--){
			cin>>q;
			dfs(q);
			int cnt=0;
			for(int i=1;i<=n;i++)if(!vis[i])cnt++;
			cout<<cnt<<' ';
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					cout<<i<<' ';
				}
			}
			cout<<endl;
			memset(vis,0,sizeof(vis));
		}
		
		memset(to,0,sizeof(to));
		
	}
	return 0;
}

