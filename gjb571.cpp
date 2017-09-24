#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char a[505][505];
bool vis[505][505][3];
int X[4]={0,1,0,-1};
int Y[4]={1,0,-1,0};

struct dest{
	int n,m,step;
	dest(){
		
	}
	dest(int x,int y,int z){
		n=x;
		m=y;
		step=z;
	}
};
int main(void){
	int n,m,ans = -1;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	queue<dest> q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='#')
				a[i][j]=0;
			else
				a[i][j]=c;
			if(c=='X'){
				q.push(dest(i,j,0));
				vis[i][j][0]=true;
			}
			
		}
	while(!q.empty()){
		dest t = q.front();
		q.pop();
		if(a[t.n][t.m]=='Y'){ans = t.step; break;}
		for(int i=0;i<4;i++){
			if( vis[ t.n+X[i] ][ t.m+Y[i] ][ (t.step+1)%3 ] != true && //是否造訪過 
			a[ t.n+X[i] ][ t.m+Y[i] ] != 0 && //是不是牆壁 
			a[ t.n+X[i] ][ t.m+Y[i] ] != (t.step+1)%3+65 ) { //是不是陷阱 
				vis[ t.n+X[i] ][ t.m+Y[i] ][ (t.step+1)%3 ]=true;
				q.push(  dest(t.n+X[i],t.m+Y[i],t.step+1)  );
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


