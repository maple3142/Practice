#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,e;
vector<int> v;
struct node{
	vector<int> v;
	bool win;
	node(){
		win=false;
	}
	void to(int a){
		v.push_back(a);
	}
};
node a[10001];
bool vis[10001];
int dfs(int now){
	vis[now]=true;
	for(int i=0;i<a[now].v.size();i++){
		if(!vis[a[now].v[i]])
			dfs(a[now].v[i]);
	}
	
	v.push_back(now);
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>e){
		if(n==0&&e==0)break;
		for(int i=0;i<e;i++){
			int x,y;
			cin>>x>>y;
			a[x].to(y);
		}
		string s;
		cin>>s;
			dfs(1);
			for(int i=0;i<v.size();i++){
				bool t=false;
				for(int k=0;k<a[v[i]].v.size();k++){//auto k:a[i].v
					if(!a[a[v[i]].v[k]].win){
						t=true;
					}
				}
				a[v[i]].win=t;
			}
			if(s[1]=='i'^a[1].win)cout<<"Mimi"<<endl;
			else cout<<"Moumou"<<endl;
		
		for(int i=0;i<n;i++){
			a[i].v.clear();
			a[i].win=false;
		}
		v.clear();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}


