#include<iostream>
#include<cstring>
#include<queue>
#include <vector>
using namespace std;
bool inq[1010];
int d[1010];

struct edge{
	int to,c;
	edge(){
		
	}
	edge(int y,int z){
		to=y;
		c=z;
	}
};

int main(void) {
	int n,m,st,ed;
	vector<edge> e[1010];
	queue<int> q;
	while(cin>>n>>m>>st>>ed){
		st--;ed--;
		for(int i=0;i<n;i++)
			e[i].clear();
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			e[a].push_back(edge(b,c));
			e[b].push_back(edge(a,c));
		}
		memset(inq,0,sizeof(inq));
		for(int i=0;i<n;i++)
			if(i==st)
				d[i]=0;
			else
				d[i]=1000000000;
		
		
		q.push(st);
		while(!q.empty()){
			int tmp=q.front();
			q.pop();
			inq[tmp]=false;
			
			for(int i=0;i<e[tmp].size();i++){
				int t=e[tmp][i].to,f=tmp;
				if(d[t]>d[f]+e[tmp][i].c){ 
					d[t]=d[f]+e[tmp][i].c;
					if(!inq[t]){
						q.push(t);
						inq[t]=true;
					}
				}
			}
		}
		if(d[ed]==1000000000)
			cout<<"He is very hot"<<endl;
		else
			cout<<d[ed]<<endl;
	}
	}




