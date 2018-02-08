#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

int getId_cnt=0;
unordered_map<string,int> getId_map;
int getId(string name){
	if(getId_map.find(name)==getId_map.end()){
		getId_map[name]=getId_cnt++;
	}
	return getId_map[name]; 
}

vector<int> m[2005];
bool vis[2005];
int dis[2005][2005];

void dfs(int now,int st,int d=0){
	if(!dis[now][st] || dis[now][st]>d)dis[now][st]=dis[st][now]=d;
	vis[now]=true;
	for(int city:m[now]){
		if(!vis[city])dfs(city,st,d+1);
	}
	vis[now]=false;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string a,b;
		while(true){
			cin>>a>>b;
			if(a==b&&a=="=")break;
			int aa=getId(a);
			int bb=getId(b);
			m[aa].push_back(bb);
			m[bb].push_back(aa);
			dis[aa][bb]=dis[bb][aa]=1;
		}
		int mx=0;
		for(int i=0;i<getId_cnt;i++){
			dfs(i,i);
			for(int j=i+1;j<getId_cnt;j++){
				mx=max(mx,dis[i][j]);
			}
		}
		cout<<mx<<endl;
		
		memset(m,0,sizeof(m));
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		getId_cnt=0;
		getId_map.clear();
	}
	return 0;
}
