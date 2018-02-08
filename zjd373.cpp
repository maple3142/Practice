#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

struct P{
	int x,y,n;
	P(int x,int y,int n=0):x(x),y(y),n(n){}
	bool operator==(const P &p)const{
		return x==p.x&&y==p.y;
	}
};
int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
bool vis[1500][1500];
int main(void){
	ios::sync_with_stdio(false);
	int r,c;
	while(cin>>r>>c){
		queue<P> q;
		vector<P> end;
		
		string a;
		cin>>a; //.mb
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=min(x1,x2);i<=max(x1,x2);i++){
			for(int j=min(y1,y2);j<=max(y1,y2);j++){
				q.push(P(i,j));
			}
		}
		cin>>a; //.cb
		cin>>x1>>y1>>x2>>y2;
		for(int i=min(x1,x2);i<=max(x1,x2);i++){
			for(int j=min(y1,y2);j<=max(y1,y2);j++){
				end.push_back(P(i,j));
			}
		}
		
		cin>>a; //.bb
		while(cin>>a){
			if(a==".be"){
				break;
			}
			x1=stoi(a);
			cin>>y1>>x2>>y2;
			
			for(int i=min(x1,x2);i<=max(x1,x2);i++){
				for(int j=min(y1,y2);j<=max(y1,y2);j++){
					vis[i][j]=true;
				}
			}
		}
		
		
		int ans=-1;
		//bfs
		while(!q.empty()){
			P now=q.front();
			q.pop();
			if(find(end.begin(),end.end(),now)!=end.end()){
				ans=now.n;
				break;
			}
			for(int i=0;i<4;i++){
				int x=now.x+X[i];
				int y=now.y+Y[i];
				if(x>=0&&x<r&&y>=0&&y<c&&!vis[x][y]){
					vis[x][y]=true;
					q.push(P(x,y,now.n+1));
				}
			}
		}
		if(ans<0){ //不能用q.empty()來檢查 
			cout<<"no path"<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}

