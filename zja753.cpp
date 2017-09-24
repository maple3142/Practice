#include<iostream>
#include<cstring>
using namespace std;

int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
int ar[32][32]={};
bool vis[32][32]={};
int cnt=0;
void DFS(int x,int y,int f){
	cnt++;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
		if(!vis[ x+X[i] ][ y+Y[i] ] && ar[ x+X[i] ][ y+Y[i] ]==f)
			DFS(x+X[i],y+Y[i],f);
}
int main(void){
	ios::sync_with_stdio(false);
	int a,b;
	while(cin>>a>>b){
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				cin>>ar[i][j];
		int n;
		cin>>n;
		for(int q=0;q<n;q++){
			int f;
			cin>>f;
			int mx=0;
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					cnt=0;
					if(ar[i][j]==f && !vis[i][j]){
						DFS(i,j,f);
						mx=max(cnt,mx);
					}
				}
			}
			cout<<(mx<2?0:mx)<<endl;
			memset(vis,0,sizeof(vis));
		}
	}
	return 0;
}

