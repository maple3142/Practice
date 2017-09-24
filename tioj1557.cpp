#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> ar[10001];
int cnt[10001]={};
bool vis[10001]={};
int start,ed;
int DFS(int dest){
	if(dest==ed)return 1;
	if(cnt[dest]!=-1)return cnt[dest];
	vis[dest]=true;
	cnt[dest]=0;
	for(auto i:ar[dest]){
		if(!vis[i])
			cnt[dest]+=DFS(i);
		else
			return 0;
		cnt[dest]%=1073741824;
	}
	vis[dest]=false;
	//cout<<dest<<" "<<cnt[dest]<<endl;
	return cnt[dest];
}
int main(void){
	int n,m;
	while(cin>>n>>m){
		memset(ar,0,sizeof(ar));
		memset(cnt,-1,sizeof(cnt));
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			ar[x].push_back(y);
		}
		
		cin>>start>>ed;
		cout<<DFS(start)<<endl;
	}
	return 0;
}


