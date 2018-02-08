#include<iostream>
using namespace std;
typedef long long int ll;

const int MX=505;

ll n,m,ans=0;
ll ar[MX][MX];
bool vis[MX][MX];
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
bool ar2[MX][MX];
void dfs(int x,int y,ll cur=0){
	bool cantwalk=true;
	for(int i=0;i<4;i++){
		int xx=x+X[i];
		int yy=y+Y[i];
		if(vis[xx][yy])continue;
		if(xx<1||xx>m)continue;
		if(yy<1||yy>n)continue;
		cantwalk=false;
		vis[xx][yy]=true;
		dfs(xx,yy,cur+ar[xx][yy]);
		vis[xx][yy]=false;
	}
	if(cantwalk){
		ans=max(ans,cur);

		int spc=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[j][i])spc++;
			}
		}
		if(spc>=2)return;
		//cout<<"================="<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				//cout<<vis[j][i];
				if(!vis[j][i])ar2[j][i]=true;
			}
			//cout<<endl;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ll sum=0; //!!!!
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cin>>ar[j][i];
			ar[j][i]=1;
			sum+=ar[j][i];
		}
	}
	int x,y;
	cin>>y>>x;
	if(x==y&&y==1)cout<<sum<<endl;
	else if(n%2==0&&m%2==0)cout<<sum<<endl;
	else{
		vis[x][y]=true;
		dfs(x,y,ar[x][y]);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<ar2[j][i];
			}
			cout<<endl;
		}
	}
	return 0;
}


