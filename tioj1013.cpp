#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
struct pos{
	int x,y,t;
	pos(int a,int b,int c){
		x=a;
		y=b;
		t=c;
	}
};
bool ar[20][20];
int fire[20][20],person[20][20];
string in[]={"*****************","*...*.......**..*","**..*....*.*.*..*","*......*.**.**.**","*..**...**..**.**","**.....**..*.*..*","*....*..........*","*.....****.*...**","****.*.*........*","*****************"};
int main(void){
	ios::sync_with_stdio(false);
	int fx,fy;
	cin>>fx>>fy;
	int t;
	cin>>t;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	
	int i=0;
	for(string s:in){
		for(int j=0;j<s.length();j++){
			if(s[j]=='.')ar[i][j]=true;
		}
		i++;
	}
	memset(fire,0x3f,sizeof(fire));
	queue<pos> f;
	f.push(pos(fx,fy,1));
	while(!f.empty()){
		pos fnow=f.front();
		f.pop();
		fire[fnow.x][fnow.y]=fnow.t;
		for(int k=0;k<4;k++){
			int tx=fnow.x+X[k],ty=fnow.y+Y[k];
			if(tx==ex&&ty==ey)continue;
			if(ar[tx][ty]&&fire[tx][ty]==0x3f3f3f3f ){
				f.push(pos(tx,ty,fnow.t+1));
			}
		}
	}
	bool escape=false;
	queue<pos> s;
	s.push(pos(sx,sy,t));
	while(!s.empty()){
		pos snow=s.front();
		s.pop();
		if(snow.t>=fire[snow.x][snow.y]){
			break;
		}
		if(snow.x==ex&&snow.y==ey){
			cout<<snow.t-t<<endl;
			escape=true;
			break;
		}
		person[snow.x][snow.y]=snow.t;
		//cout<<"s("<<snow.x<<","<<snow.y<<")"<<endl;
		for(int k=0;k<4;k++){
			int tx=snow.x+X[k],ty=snow.y+Y[k];
			
			if(ar[tx][ty]&&snow.t+1<fire[tx][ty]&&person[tx][ty]==0){
				s.push(pos(tx,ty,snow.t+1));
			}
		}
	}
	if(!escape){
		cout<<"Help!"<<endl;
	}
	return 0;
}

