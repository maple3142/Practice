#include<iostream>
#include<queue>
using namespace std;

int X[4]={0,1,-1,0};
int Y[4]={-1,0,0,1};
struct N{
	int t;
	int i,j;
	N(int a,int b,int c){
		t=a;
		i=b;
		j=c;
	}
};
bool ar[102][102];
int t[102][102];
int main(void){
	cin.sync_with_stdio(false);
	int S,cse=1;
	while(cin>>S){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>ar[i][j];
				t[i][j]=0;
			}
		queue<N> q;
		for(int i=1;i<=m;i++){
			if(ar[1][i]){
				q.push(N(1,1,i));
				ar[1][i]=false;
			}
		}
		while(!q.empty()){
			N f=q.front();
			q.pop();
			t[f.i][f.j]=f.t;
			for(int i=0;i<4;i++){
				if(S==2 && i==0)continue;
				if(ar[f.i+Y[i]][f.j+X[i]]){
					q.push(N(f.t+1,f.i+Y[i],f.j+X[i]));
					ar[f.i+Y[i]][f.j+X[i]]=false;
				}
			}
		}
		cout<<"Case "<<cse<<":"<<endl;
		cse++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<t[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}


