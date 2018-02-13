#include<iostream>
#include<set>
#include<vector>
#include<cstring>
using namespace std;

const int MX=100000;

int a,b,kase=1;
int in[MX];
bool vis[MX];
vector<int> to[MX];
set<int> nodes;
bool istree=true;
void dfs(int x){
	vis[x]=true;
	for(int xx:to[x]){
		if(vis[xx]){
			istree=false;
			return;
		}
		dfs(xx);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(true){
		cin>>a>>b;
		if(a<0&&b<0)break;
		else if(a==0&&b==0){
			istree=true;
			int rootcnt=0;
			for(int x:nodes){
				if(in[x]>1){
					istree=false;
					break;
				}
				if(in[x]==0){
					rootcnt++;
				}
			}
			if(rootcnt!=1)istree=false;
			if(istree)dfs(*nodes.begin());
			if(nodes.size()==0)istree=true;
			cout<<"Case "<<kase++<<" is "<<(istree?"":"not ")<<"a tree."<<endl;
			nodes.clear();
			memset(in,0,sizeof(in));
			memset(vis,0,sizeof(vis));
			memset(to,0,sizeof(to));
		}
		else{
			in[b]++;
			nodes.insert(a);
			nodes.insert(b);
			to[a].push_back(b);
		}
	}
	return 0;
}

