#include<iostream>
#include<iomanip>
using namespace std;

const int MX=40;
int n,k;
int ar[MX][MX];
void dfs(int x,int y,int xs,int ys,int cur){
	ar[x][y]=cur;
	if(ar[x+xs][y+ys]!=0){
		int tmpx=xs;
		if(k==2){
			xs=-ys;
			ys=tmpx;
		}
		else{
			xs=ys;
			ys=-tmpx;
		}
	}
	if(cur==n*n)return;
	dfs(x+xs,y+ys,xs,ys,cur+1);
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<=n+1;i++){
		ar[0][i]=ar[i][0]=ar[n+1][i]=ar[i][n+1]=-1;
	}
	if(k==2)dfs(1,1,1,0,1);
	else dfs(1,1,0,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setfill('0')<<setw(3)<<ar[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

