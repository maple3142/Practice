#include<iostream>
#include<cstring>
using namespace std;

bool vis[50001],vis2[50001];
struct alien{
	int to=-1;
	int in=0;
}ar[50001];
int dfs(int n){
	vis[n]=vis2[n]=true;
	if(ar[n].to>=0&&!vis[ar[n].to]){
		int r=dfs(ar[n].to)+1;
		vis[n]=false;
		return r;
	}
	vis[n]=false;
	return 1;
}
int main(void){
	ios::sync_with_stdio(false);
	int T,cse=1;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u>>v;
			ar[u].to=v;
			ar[v].in++;
		}
		int mx=0,mxi=0;
		for(int i=n;i>0;i--){
			if(ar[i].in==0){
				int r=dfs(i);
				if(r>=mx){
					mx=r;
					mxi=i;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(!vis2[i]){
				int r=dfs(i);
				if(r>mx){
					mx=r;
					mxi=i;
				}
			}
		}
		cout<<"Case "<<cse++<<": "<<mxi<<endl;
		memset(vis2,0,sizeof(vis2));
		for(int i=0;i<n;i++){
			ar[i].in=0;
			ar[i].to=-1;
		}
	}
	return 0;
}

