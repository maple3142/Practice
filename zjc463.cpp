#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

const int MX=100005;
bool notroot[MX];
vector<int> children[MX];
ll sigma_height=0;
int dfs(int now,int d=-1){
	if(children[now].size()==0)return 0;
	int mxh=0;
	for(int to:children[now]){
		int h=dfs(to,d+1);
		mxh=max(mxh,h);
	}
	mxh++;
	sigma_height+=mxh;
	return mxh;
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k,a;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a;
			notroot[a]=true;
			children[i].push_back(a);
		}
	}
	int root=0;
	for(int i=1;i<=n;i++){
		if(!notroot[i]){
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<root<<'\n'<<sigma_height<<'\n';
	return 0;
}

