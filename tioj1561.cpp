#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;

struct edge{
	int f,t,w;
};
int d[105];
int d2[105];
bool inq[105];
vector<pii> to[105];
vector<edge> E;
void spfa(int st,int d[]){ //d need to memset to INF outside
	queue<int> q;
	d[st]=0;
	q.push(st);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		inq[now]=false;
		
		for(pii p:to[now]){
			if(d[p.first]>d[now]+p.second){
				d[p.first]=d[now]+p.second;
				if(!inq[p.first]){
					q.push(p.first);
					inq[p.first]=true;
				}
			}
		}
	}
	
	memset(inq,0,sizeof(inq));
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int f,t,w;
		for(int i=1;i<=m;i++){
			cin>>f>>t>>w;
			to[f].push_back(pii(t,w));
			to[t].push_back(pii(f,w));
			E.push_back((edge){f,t,w});
		}
		int st,ed;
		cin>>st>>ed;
		
		memset(d,0x3f,sizeof(d));
		spfa(st,d);
		memset(d2,0x3f,sizeof(d2));
		spfa(ed,d2);
		
		int ans=0x3f3f3f3f;
		for(edge e:E){
			if(d[e.f]+d2[e.t]+e.w>d[ed]){
				ans=min(ans,d[e.f]+d2[e.t]+e.w);
			}
			if(d2[e.f]+d[e.t]+e.w>d[ed]){
				ans=min(ans,d2[e.f]+d[e.t]+e.w);
			}
		}
		cout<<(ans!=0x3f3f3f3f?ans:-1)<<endl;
		
		memset(to,0,sizeof(to));
		E.clear();
	}
	
	return 0;
}

