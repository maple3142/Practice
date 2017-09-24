#include<iostream>
#include<cstring>
using namespace std;

int n,x1,y1,z1,x2,y2,z2,k;
bool vis[3001][3001]={};
bool dfs(int x,int y,int z){
	if(x<0||y<0||z<0)return false;
	if(x>n||y>n||z>n)return false;
	if(x==x2&&y==y2&&z==z2)return true;
	vis[x][y]=true;
	bool a=false;
	//1
	if(!vis[y][x])
		a=max(dfs(y,x,z),a);
	//2
	if(!vis[x][z])
		a=max(dfs(x,z,y),a);
	//3
	if(!vis[z][y])
		a=max(dfs(z,y,x),a);
	//4
	int o=2*y-x+1;
	int p=2*x-y-1;
	if(o>0&&p>0&&o<=n&&p<=n)
		if(!vis[o][p])
			a=max(dfs(o,p,z),a);
	return a;
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0){
			break;
		}
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		if(x1+y1+z1!=x2+y2+z2)
			cout<<"No"<<endl;
		else
			cout<<(dfs(x1,y1,z1)?"Yes":"No")<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}


