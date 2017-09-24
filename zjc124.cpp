#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//up down left right front back
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,-1,1,0,0};
int Z[6]={1,-1,0,0,0,0};
struct N{
	int t;
	int i,j,k;
	N(){
		
	}
	N(int a,int b,int c,int d){
		t=a;
		i=b;
		j=c;
		k=d;
	}
	bool operator==(N a){
		if(i==a.i && j==a.j && k==a.k)return true;
		return false;
	}
};
bool ar[52][52][52]={};
N last[52][52][52]={};
int main(void){
	cin.sync_with_stdio(false);
	int l,r,c;
	while(cin>>l>>r>>c){
		queue<N> q;
		N ed=N(0,c,r,l);
		for(int i=1;i<=c;i++)
			for(int j=1;j<=r;j++)
				for(int k=1;k<=l;k++){
					bool b;
					cin>>b;
					ar[i][j][k]=!b;
				}
		bool escape=false;
		if(ar[1][1][1])
			q.push(N(0,1,1,1));
		while(!q.empty()){
			N f=q.front();
			q.pop();
			if(f==ed){
				stack<N> s;
				while(f.t!=0){
					s.push(f);
					f=last[f.i][f.j][f.k];
				}
				cout<<"(1,1,1)"<<(ed==N(0,1,1,1)?"":"->");
				while(!s.empty()){
					N n=s.top();
					s.pop();
					cout<<"("<<n.k<<","<<n.j<<","<<n.i<<")"<<(s.size()>=1?"->":"");
				}
				cout<<endl;
				escape=true;
			}
			else
				for(int i=0;i<6;i++){
					if(ar[ f.i+X[i] ][ f.j+Y[i] ][ f.k+Z[i] ]){
						last[ f.i+X[i] ][ f.j+Y[i] ][ f.k+Z[i] ]=f;
						q.push(N(f.t+1,f.i+X[i],f.j+Y[i],f.k+Z[i]));
						ar[ f.i+X[i] ][ f.j+Y[i] ][ f.k+Z[i] ]=false;
					}
				}
		}
		if(!escape)cout<<"no route"<<endl;
	}
	return 0;
}


