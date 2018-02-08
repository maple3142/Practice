#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;

const int MX=51;
const int MOD=100000;
bool ar[MX][MX];
int d[MX][MX];
int cnt[MX][MX];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		memset(d,0x3f,sizeof(d));
		memset(cnt,0,sizeof(cnt));
		memset(ar,0,sizeof(ar));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ar[i][j];
			}
		}
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		sx++,sy++,ex++,ey++;
		queue<pii> q;
		q.push(pii(sx,sy));
		d[sx][sy]=0;
		cnt[sx][sy]=1;
		while(!q.empty()){
			pii now=q.front();
			q.pop();
			
			for(int i=0;i<4;i++){
				int x=now.first+X[i];
				int y=now.second+Y[i];
				
				if(x<1||x>n)continue;
				if(y<1||y>n)continue;
				if(ar[x][y])continue;
				
				if(d[x][y]==d[now.first][now.second]+1){
					cnt[x][y]+=cnt[now.first][now.second];
					cnt[x][y]%=MOD;
				}
				if(d[x][y]>d[now.first][now.second]+1){
					d[x][y]=d[now.first][now.second]+1;
					cnt[x][y]=cnt[now.first][now.second];
					q.push(pii(x,y));
				}
			}
		}
		cout<<cnt[ex][ey]<<endl;
	}
	return 0;
}

