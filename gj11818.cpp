#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

struct stick{
	int x1,y1,x2,y2;
	stick(int a,int b,int c,int d){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
	}
	operator==(const stick &x)const{
		return (x1==x.x1) &&
		(y1==x.y1)&&
		(x2==x.x2)&&
		(y2==x.y2);
	}
};
namespace std {
	template <> struct hash<stick>{
		int operator()(const stick &x)const{
			return x.x1*1000+x.y1*100+x.x2*10+x.y2;
		}
	};
}
unordered_map<stick,int> m;
bool removed[13];
bool ok[10][10];
bool vis[10];
bool res[1<<12];
vector<int> to[10];
void init(){
	m[stick(1,0,1,1)]=m[stick(1,1,1,0)]=1;
	m[stick(2,0,2,1)]=m[stick(2,1,2,0)]=2;
	m[stick(0,1,1,1)]=m[stick(1,1,0,1)]=3;
	m[stick(1,1,2,1)]=m[stick(2,1,1,1)]=4;
	m[stick(2,1,3,1)]=m[stick(3,1,2,1)]=5;
	m[stick(1,1,1,2)]=m[stick(1,2,1,1)]=6;
	m[stick(2,1,2,2)]=m[stick(2,2,2,1)]=7;
	m[stick(0,2,1,2)]=m[stick(1,2,0,2)]=8;
	m[stick(1,2,2,2)]=m[stick(2,2,1,2)]=9;
	m[stick(2,2,3,2)]=m[stick(3,2,2,2)]=10;
	m[stick(1,2,1,3)]=m[stick(1,3,1,2)]=11;
	m[stick(2,2,2,3)]=m[stick(2,3,2,2)]=12;
}
void init2(int S){
	ok[1][2]=ok[2][1]=S&(1<<1);
	ok[2][3]=ok[3][2]=S&(1<<2);
	ok[1][4]=ok[4][1]=S&(1<<3);
	ok[2][5]=ok[5][2]=S&(1<<4);
	ok[3][6]=ok[6][3]=S&(1<<5);
	ok[4][5]=ok[5][4]=S&(1<<6);
	ok[5][6]=ok[6][5]=S&(1<<7);
	ok[4][7]=ok[7][4]=S&(1<<8);
	ok[5][8]=ok[8][5]=S&(1<<9);
	ok[6][9]=ok[9][6]=S&(1<<10);
	ok[7][8]=ok[8][7]=S&(1<<11);
	ok[8][9]=ok[9][8]=S&(1<<12);
}
void init3(){
	for(int i=1;i<=9;i++){
		if(i-3>0)to[i].push_back(i-3);
		if(i+3<10)to[i].push_back(i+3);
		switch(i%3){
			case 1:
				to[i].push_back(i+1);
				break;
			case 2:
				to[i].push_back(i+1);
				to[i].push_back(i-1);
				break;
			case 0:
				to[i].push_back(i-1);
				break;
		}
	}
}
void init4(){
	ok[1][2]=ok[2][1]=!removed[1];
	ok[2][3]=ok[3][2]=!removed[2];
	ok[1][4]=ok[4][1]=!removed[3];
	ok[2][5]=ok[5][2]=!removed[4];
	ok[3][6]=ok[6][3]=!removed[5];
	ok[4][5]=ok[5][4]=!removed[6];
	ok[5][6]=ok[6][5]=!removed[7];
	ok[4][7]=ok[7][4]=!removed[8];
	ok[5][8]=ok[8][5]=!removed[9];
	ok[6][9]=ok[9][6]=!removed[10];
	ok[7][8]=ok[8][7]=!removed[11];
	ok[8][9]=ok[9][8]=!removed[12];
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	init();
	init3();
	while(T--){
		int s,c,r;
		cin>>s>>c>>r;
		for(int i=1;i<=r;i++){
			int e,f,g,h;
			cin>>e>>f>>g>>h;
			removed[m[stick(e,f,g,h)]]=true;
		}
		init4();
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int n=q.front();
			vis[n]=true;
			if(n==c){
				cout<<"No Cheese!"<<endl;
				break;
			}
			q.pop();
			for(int d:to[n]){
				if(ok[n][d] && !vis[d]){
					q.push(d);
				}
			}
		}
		
		if(!q.size()){
			int K=1<<12;
			for(int S=0;S<K;S++){
				int rmc=0;
				bool cont=false;
				for(int i=0;i<12;i++){
					if(removed[i] && S&(1<<i)){
						cont=true;
						break;
					}
					else if(!removed[i] && !(S&(1<<i)) ){
						rmc++;
					}
				}
				if(cont)continue;
				
				init2(S);
				memset(vis,0,sizeof(vis));
				
				queue<int> q;
				q.push(s);
				while(!q.empty()){
					int n=q.front();
					vis[n]=true;
					if(n==c){
						if(rmc%2){
							res[S]=true;
						}
					}
					q.pop();
					for(int d:to[n]){
						if(ok[n][d] && !vis[d]){
							q.push(d);
						}
					}
				}
			}
			int S=0;
			for(int i=0;i<12;i++){
				if(!removed[i])
					S=S&(1<<i);
			}
			cout<<(res[S]?"SOHA":"TARA")<<endl;
		}
	}
	return 0;
}

