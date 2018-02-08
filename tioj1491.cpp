#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<iterator>
using namespace std;

set<string> cities;
unordered_map<string,vector<string>> m;
unordered_map<string,bool> vis;
unordered_map<string,unordered_map<string,int>> dis;
void dfs(string now,string st,int d=0){
	if(!dis[now][st] || dis[now][st]>d)dis[now][st]=dis[st][now]=d;
	vis[now]=true;
	for(string city:m[now]){
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
			cities.insert(a);
			cities.insert(b);
			m[a].push_back(b);
			m[b].push_back(a);
			dis[a][b]=dis[b][a]=1;
		}
		dfs(*cities.begin(),*cities.begin());
		cout<<"dfs end"<<endl;
		int mx=0;
		for(auto it=cities.begin();it!=cities.end();it++){
			for(auto jt=next(it,1);jt!=cities.end();jt++){
				mx=max(mx,dis[*it][*jt]);
			}
		}
		cout<<mx<<endl;
		m.clear();
		vis.clear();
		dis.clear();
		cities.clear();
	}
	return 0;
}

