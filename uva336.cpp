#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct pkg{
	int now;
	int ttl;
};
struct point{
	vector<int> to;
};
int main(void){
	ios::sync_with_stdio(false);
	int n,cse=1;
	while(cin>>n){
		if(n==0)break;
		unordered_map<int,point> mp;
		unordered_map<int,bool> vis;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			mp[a].to.push_back(b);
			mp[b].to.push_back(a);
		}
		int a,b;
		while(cin>>a>>b){
			if(!(a||b))break;
			queue<pkg> q;
			q.push((pkg){a,b});
			while(!q.empty()){
				pkg p=q.front();
				q.pop();
				vis[p.now]=true;
				if(p.ttl==0)continue;
				for(int pp:mp[p.now].to){
					if(!vis[pp])
						q.push((pkg){pp,p.ttl-1});
				}
			}
			int cnt=0;
			for(const pair<int,point>& pr:mp){
				if(!vis[pr.first])
					cnt++;
			}
			cout<<"Case "<<cse++<<": "<<cnt<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl; 
			vis.clear();
		}
	}
	return 0;
}

