#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long int ll;

struct point{
	vector<int> to;
	ll dis=0x3f3f3f3f;
	int count=-1;
}ar[1005];
ll dis[1005][1005];
bool vis[1005];
int dfs(int now){
	if(now==2)return 1;
	ar[now].count=0;
	for(int p:ar[now].to){
		if(ar[p].dis>ar[now].dis)continue;
		if(ar[p].count==-1){
			ar[now].count+=dfs(p);
		}
		else{
			ar[now].count+=ar[p].count;
		}
	}
	return ar[now].count;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n){
		if(n==0)break;
		cin>>m;
		for(int i=0;i<m;i++){
			int a,b,d;
			cin>>a>>b>>d;
			ar[a].to.push_back(b);
			ar[b].to.push_back(a);
			dis[a][b]=dis[b][a]=d;
		}
		ar[2].dis=0;
		vis[2]=true;
		int now=2;
		for(int i=0;i<n-1;i++){
			vis[now]=true;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&dis[now][j]!=0){
					if(ar[j].dis>ar[now].dis+dis[j][now]){
						ar[j].dis=ar[now].dis+dis[j][now];
					}
				}
			}
			ll mn=0x3f3f3f3f,mni=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&ar[j].dis<mn){
					mn=ar[j].dis;
					mni=j;
				}
			}
			now=mni;
		}
		cout<<dfs(1)<<endl;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++){
			ar[i].count=-1;
			ar[i].dis=0x3f3f3f3f;
			ar[i].to.clear();
		}
	}
	return 0;
}

