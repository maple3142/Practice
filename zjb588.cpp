#include<iostream>
using namespace std;

const int MX=101;
bool hasval[MX][MX][MX];
bool dp[MX][MX][MX];
bool dfs(int x,int y,int z){
	if(x==0&&y==0&&z==0)return false;
	if(x>y)swap(x,y);
	if(x>z)swap(x,z);
	if(y>z)swap(y,z);
	if(hasval[x][y][z])return dp[x][y][z];
	bool r=false;
	for(int i=x;i>=1&&!r;i--)r=!dfs(x-i,y,z);
	for(int i=y;i>=1&&!r;i--)r=!dfs(x,y-i,z);
	for(int i=z;i>=1&&!r;i--)r=!dfs(x,y,z-i);
	for(int i=min(x,y);i>=1&&!r;i--)r=!dfs(x-i,y-i,z);
	for(int i=min(x,z);i>=1&&!r;i--)r=!dfs(x-i,y,z-i);
	for(int i=min(y,z);i>=1&&!r;i--)r=!dfs(x,y-i,z-i);
	for(int i=min(x,min(y,z));i>=1&&!r;i--)r=!dfs(x-i,y-i,z-i);
	hasval[x][y][z]=true;
	//cout<<x<<' '<<y<<' '<<z<<' '<<(r?'w':'l')<<endl;
	return dp[x][y][z]=r;
}

int main(void){
	ios::sync_with_stdio(false);
	int x,y,z;
	while(cin>>x){
		if(x==0)break;
		cin>>y>>z;
		cout<<(dfs(x,y,z)?'w':'l')<<endl;
	}
	return 0;
}

