#include<iostream>
using namespace std;

int ar[2005];
bool vis[2005];
int dfs(int x){
	if(vis[x])return 0;
	vis[x]=true;
	int r=dfs(ar[x])+1;
	vis[x]=false;
	return r;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dfs(i));
	}
	cout<<mx<<endl;
	return 0;
}

