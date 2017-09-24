#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int min(int a,int b){
	return a<b?a:b;
}
struct trip{
	int to;
	bool isrev;
	trip(){
		isrev=false;
	}
	trip(int a){
		to=a;
		isrev=false;
	}
};
struct Node{
	vector<trip> v;
	bool isrev;
	Node(){
		
	}
	void to(int a){
		v.push_back(trip(a));
	}
	void revto(int a){
		trip t=trip(a);
		t.isrev=true;
		v.push_back(t);
	}
};
Node ns[1005];
bool vis[1005];
int d[1005];
int n,ma,mb,k,st,ed,mn=1000000;
void dfs(int now,int cnt){
	if(now==ed){
		mn=min(cnt,mn);
		return;
	}
	vis[now]=true;
	vector<trip> v=ns[now].v;
	for(int i=0;i<v.size();i++){
		if(!vis[v[i].to]){
			if(!v[i].isrev)
				dfs(v[i].to,cnt+1);
			else
				dfs(v[i].to,cnt);
		}
	}
	vis[now]=false;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>ma>>mb>>k>>st>>ed;
		for(int i=0;i<ma;i++){
			int u,v;
			cin>>u>>v;
			ns[u].to(v);
		}
		for(int i=0;i<mb;i++){
			int u,v;
			cin>>u>>v;
			ns[v].revto(u);
		}
		//dfs(st,0);
		int now=st;
		for(int i=0;i<n-1;i++){
			vis[now]=true;
			vector<trip> v=ns[now].v;
			for(int j=0;j<v.size();j++){
				if(!vis[v[i].to]){
					if(!v[i].isrev)
						if(d[j]>d[now])d[j]=d[now]+1;
					else
						if(d[j]>d[now])d[j]=d[now];
				}
			}
			for(int j=0;j<n;j++)
				if(d[j]<mn&&!vis[j])
					now=j,mn=d[j];
		}
		cout<<mn<<endl;
		cout<<(mn<=k?"Yes.":"No.")<<endl;
		for(int i=0;i<n;i++){
			ns[i].v.clear();
		}
		mn=1000000;
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
	}
	return 0;
}


