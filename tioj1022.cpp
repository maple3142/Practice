#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<ll,ll> pii;

struct poll{
	ll x,y,oil;
	poll(ll x,ll y,ll o):x(x),y(y),oil(o){}
};
ll X[]={1,0,-1,0};
ll Y[]={0,1,0,-1};
ll ar[101][101];
bool vis[101][101];
ll main(void){
	ios::sync_with_stdio(false);
	ll k;
	cin>>k;
	while(k--){
		ll m,n;
		cin>>m>>n;
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=n;j++){
				cin>>ar[i][j];
			}
		}
		
		ll oil;
		queue<poll> q;
		q.push(poll(1,1,0));
		while(!q.empty()){
			poll now=q.front();
			q.pop();
			
			if(now.x==m&&now.y==n){
				oil=now.oil;
				break;
			}
			
			ll nh=ar[now.x][now.y];
			for(ll i=0;i<4;i++){
				ll dx=now.x+X[i];
				ll dy=now.y+Y[i];
				if(dx<=m&&dx>=1&&dy<=n&&dy>=1&&abs(ar[dx][dy]-nh)<=5&&!vis[dx][dy]){
					q.push(poll(dx,dy,now.oil+1));
					vis[dx][dy]=true;
				}
			}
		}
		cout<<oil<<endl;
		while(!q.empty()){
			q.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

