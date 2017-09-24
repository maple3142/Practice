#include<iostream>
using namespace std;

char ar[105][105];
bool vis[105][105];
int X[8]={0,0,-1,1,-1,-1,1,1};
int Y[8]={1,-1,0,0,1,-1,1,-1};
void Ddfs(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<8;i++){
		if(!vis[x+X[i]][y+Y[i]]&&ar[x+X[i]][y+Y[i]]=='G')
			Ddfs(x+X[i],y+Y[i]);
	}
}
void Edfs(int x,int y){
	vis[x][y]=true;
	for(int i=0;i<8;i++){
		if(!vis[x+X[i]][y+Y[i]]&&ar[x+X[i]][y+Y[i]]=='-')
			Edfs(x+X[i],y+Y[i]);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int w,h;
	cin>>w>>h;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>ar[i][j];
		}
	}
	int dc=0,ec=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!vis[i][j]){
				if(ar[i][j]=='G'){
					Ddfs(i,j);
					dc++;
				}
				else if(ar[i][j]=='-'){
					Edfs(i,j);
					ec++;
				}
			}
		}
	}
	cout<<dc<<" "<<ec<<endl;
	return 0;
}


