#include<iostream>
using namespace std;

int n,s;
int ar[50][50];
bool vis[50][50];

int R[]={0,-1,0,1};
int C[]={-1,0,1,0};

int turn(int n){
	if(n==3)return 0;
	return n+1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>ar[i][j];
	int r=n/2+1,c=n/2+1;
	for(int u=1;u<=n*n;u++){
		vis[r][c]=true;
		cout<<ar[r][c];
		if(!vis[r+R[turn(s)]][c+C[turn(s)]]&&u!=1){
			s=turn(s);
			r=r+R[s];
			c=c+C[s];
		}
		else if(!vis[r+R[s]][c+C[s]]){
			r=r+R[s];
			c=c+C[s];
		}
	}
	cout<<endl;
	return 0;
}

