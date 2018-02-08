#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct cord{
	int x;
	int y;
	int step;
	cord(){
		
	}
	cord(int a,int b,int c){
		x=a;
		y=b;
		step=c;
	}
};
string s[101];
queue<cord> q;
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		if(n==0)break;
		int kx,ky;
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<s[i].length();j++){
				if(s[i][j]=='K'){
					kx=i;
					ky=j;
				}
			}
		}
		q.push(cord(kx,ky,1));
		bool yes=false;
		while(!q.empty()&&!yes){
			cord t=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int xx=t.x+X[i];
				int yy=t.y+Y[i];
				if(s[xx][yy]=='.'){
					q.push(cord(xx,yy,t.step+1));
					s[xx][yy]='#';
				}
				else if(s[xx][yy]=='@'){
					cout<<t.step<<endl;
					yes=true;
					break;
				}
			}
		}
		while(!q.empty())q.pop();
		if(!yes)cout<<"= =\""<<endl;
	}
	return 0;
}
