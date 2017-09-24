#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

string ppp[1001][1001];
struct P{
	bool first;
	int px,py;
	int x,y;
	P(){
		
	}
	P(int a,int b){
		x=a;
		y=b;
		first=true;
	}
	P(int a,int b,int c,int d,string m){
		x=a;
		y=b;
		px=c;
		py=d;
		ppp[x][y]=m;
	}
	void print(){
		cout<<x<<" "<<y<<endl;
	}
};
//P aaa[1001][1001];
bool vis[1001][1001];
int main(void){
	ios::sync_with_stdio(false);
	int a,b,n;
	while(cin>>a>>b>>n){
		cout << "!";
		queue<P> q;
		vis[0][0]=true;
		q.emplace(0,0);
		P p;
		while(!q.empty()){
			P now=q.front();
			q.pop();
			if(now.x==n||now.y==n){
				p=now;
				break;
			}
			if(!vis[a][now.y])q.emplace(a,now.y,now.x,now.y,"fill A"),vis[a][now.y]=true;
			if(!vis[now.x][b])q.emplace(now.x,b,now.x,now.y,"fill B"),vis[now.x][b]=true;
			if(!vis[0][now.y])q.emplace(0,now.y,now.x,now.y,"empty A"),vis[0][now.y]=true;
			if(!vis[now.x][0])q.emplace(now.x,0,now.x,now.y,"empty B"),vis[now.x][0]=true;
			{
				int x=now.x;
				int y=now.y;
				if(y>a-x){
					x=a;
					y-=(a-x);
				}
				if(!vis[x][y])q.emplace(x,y,now.x,now.y,"pour B A"),vis[x][y]=true;
			}
			{
				int y=now.x;
				int x=now.y;
				if(y>a-x){
					x=a;
					y-=(a-x);
				}
				if(!vis[x][y])q.emplace(x,y,now.x,now.y,"pour A B"),vis[x][y]=true;
			}
			//aaa[now.x][now.y]=now;
			cout << "!!";
		}
		
		stack<string> s;
		s.push("success");
		while(p.first!=true){
//			s.push(ppp[p.x][p.y]);
//			p=aaa[p.x][p.y];
		}
		while(!s.empty()){
			cout<<s.top()<<endl;
			s.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

