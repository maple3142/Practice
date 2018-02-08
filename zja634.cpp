#include<iostream>
#include<cstring>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int d[10][10];
bool inq[10][10];
int XX[]={2,1,-1,-2,-2,-1,1,2};
int YY[]={1,2,2,1,-1,-2,-2,-1}; 
int main(void){
	ios::sync_with_stdio(false);
	memset(d,0x3f,sizeof(d));
	
	int x1,y1,x2,y2;
	char t1,t2;
	cin>>t1>>y1>>t2>>y2; //c6 c5
	x1=t1-'a'+1;
	x2=t2-'a'+1;
	d[x1][y1]=0;
		
	char t;
	int x,y;
	while(cin>>t>>y){
		if(t==x)break;
		x=t-'a'+1;
		inq[x][y]=true;
	}
	
	queue<pii> q;
	q.push(pii(x1,y1));
	inq[x1][y1]=true;
	while(!q.empty()){
		pii now=q.front();
		q.pop();
		inq[now.X][now.Y]=false;
		
		for(int i=0;i<8;i++){
			x=now.X+XX[i];
			y=now.Y+YY[i];
			if(x>8||x<1||y>8||y<1)continue;
			
			if(d[x][y]>d[now.X][now.Y]+1){
				d[x][y]=d[now.X][now.Y]+1;
				if(!inq[x][y]){
					inq[x][y]=true;
					q.push(pii(x,y));
				}
			}
		}
	}
	cout<<"The shortest solution is "<<d[x2][y2]<<" move(s)."<<endl;
	return 0;
}

