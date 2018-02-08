#include<iostream>
#include<queue>
#include<cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int n;
const int INF=0x3f3f3f3f;
int ar[25][25];
int d[25][25];
int d2[25][25];
int XX[]={1,0,-1,0};
int YY[]={0,1,0,-1};
void print(int d[25][25]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<d[i][j]<<' ';
		}
		cout<<endl;
	}
}
void spfa(pii start,int d[25][25]){
	bool vis[25][25];
	queue<pii> q;
	q.push(start);
	d[start.X][start.Y]=ar[start.X][start.Y];
	vis[start.X][start.Y]=true;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			if(i==0||i==n+1||j==0||j==n+1)vis[i][j]=true;
		}
	}
	while(!q.empty()){
		pii now=q.front();
		q.pop();
		vis[now.X][now.Y]=false;	
		for(int i=0;i<4;i++){
			int x=now.X+XX[i];
			int y=now.Y+YY[i];
			if(d[x][y]>d[now.X][now.Y]+ar[x][y]){
				d[x][y]=d[now.X][now.Y]+ar[x][y];
				if(!vis[x][y]){
					q.push(pii(x,y));
					vis[x][y]=true;
				}
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ar[i][j];
		}
	}
	int Q,sx,sy,ex,ey;
	cin>>Q;
	while(Q--){
		cin>>sx>>sy>>ex>>ey;
		
		memset(d,0x3f,sizeof(d));
		spfa(pii(sx,sy),d);
		memset(d2,0x3f,sizeof(d2));
		spfa(pii(ex,ey),d2);
		
		int mn=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mn=min(mn,d[i][j]+d2[i][j]-2*ar[i][j]);
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}

