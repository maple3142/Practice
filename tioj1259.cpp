#include<iostream>
using namespace std;

ll n,xa,ya,xb,yb,cnt=0;
ll X[]={1,0,-1,0};
ll Y[]={0,1,0,-1};
bool vis[8][8];
bool is(ll x,ll y){
	if(vis[x][y])return false;
	ll cnt=0;
	for(ll i=0;i<4;i++){
		if(vis[x+X[i]][y+Y[i]]){
			cnt++;
		}
		
	}
	return cnt>=2;
}
bool has2(ll x,ll y){
	ll cnt=0;
	for(ll i=0;i<4;i++){
		if(is(x+X[i],y+Y[i])){
			cnt++;
		}
	}
	return cnt>=2;
}
void dfs(ll x,ll y,ll fill){
	
	/*
	if(x==1)vis[0][y]=true;
	if(x==n)vis[n+1][y]=true;
	if(y==1)vis[x][0]=true;
	if(y==n)vis[x][n+1]=true;
	*/
	
	if(x>n||x<1||y>n||y<1){
		return;
	}
	
	if(fill==n*n&&x==xb&&y==yb){
		cnt++;
		return;
	}
	
	if( ((vis[x+X[0]][y+Y[0]]&&vis[x+X[2]][y+Y[2]]&&!vis[x+X[1]][y+Y[1]]&&!vis[x+X[3]][y+Y[3]]) || 
		(vis[x+X[1]][y+Y[1]]&&vis[x+X[3]][y+Y[3]]&&!vis[x+X[0]][y+Y[0]]&&!vis[x+X[2]][y+Y[2]])) && n*n-fill>1 ){
		return;
	}
	
	if(has2(x,y)){
		return;
	}
	
	for(ll i=0;i<4;i++){
		ll dx=x+X[i];
		ll dy=y+Y[i];
		if(!vis[dx][dy]){
			vis[dx][dy]=true;
			dfs(dx,dy,fill+1);
			vis[dx][dy]=false;
		}
	}
} 
ll main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>xa>>ya>>xb>>yb){
		vis[xa][ya]=true;
		dfs(xa,ya,1);
		vis[xa][ya]=false;
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}

