#include<iostream>
#include<queue>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int XX[]={1,-1,0,0};
int YY[]={0,0,1,-1};
queue<pii> snake;
vector<int> range(int a,int b){
	vector<int> v;
	if(a>b){
		for(int i=a;i>=b;i--)v.push_back(i);
	}
	else{
		for(int i=a;i<=b;i++)v.push_back(i);
	}
	return v;
}
bool mp[1005][1005];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	sx++,sy++,ex++,ey++;
	for(int y:range(ey,sy)){
		snake.push(pii(sx,y));
		mp[sx][y]=true;
	}
	bool F=false;
	int q,d;
	cin>>q;
	while(q--){
		cin>>d;
		sx+=XX[d];
		sy+=YY[d];
		if(mp[sx][sy]||sx<1||sx>m||sy<1||sy>n){
			break;
		}
		
		pii t=snake.front();
		mp[t.X][t.Y]=false;
		snake.pop();
		sx+=XX[d];
		sy+=YY[d];
		snake.push(pii(sx,sy));
		mp[sx][sy]=true;
	}
	//if(F)return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	return 0;
}

