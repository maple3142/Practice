#include<iostream>
#include<vector>
using namespace std;

struct node{
	vector<int> v;
	bool vis;
	int tag;
	node(){
		vis=false;
		tag=0;
	}
	void to(int a){
		v.push_back(a);
	}
};
node a[40001];
bool dfs(int now,int tag){
	a[now].vis=true;
	if(!a[now].tag)
		a[now].tag=tag;
	bool rtn=true;
	for(auto i:a[now].v){
		if(a[i].tag==a[now].tag)rtn=false;
		if(!a[i].vis)
			rtn=min(rtn,dfs(i,(tag==1?2:1)));
	}
	return rtn;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		if(n==m&&n==0)break;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			a[x].to(y);
			a[y].to(x);
		}
		cout<<(dfs(1,1)?"Yes":"No")<<endl;
		for(int i=0;i<=n;i++){
			a[i].v.clear();
			a[i].vis=false;
			a[i].tag=0;
		}
	}
	return 0;
}


