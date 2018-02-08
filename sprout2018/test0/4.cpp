#include<iostream>
#include<cmath>
using namespace std;

const int MX=2005;
int n,m,q,a,c,x,y,r;
int ar[MX][MX];
void paintHori(int c,int x){
	int aa=x!=1?x-1:1;
	int bb=x;
	int cc=x!=n?x+1:n;
	for(int i=1;i<=m;i++){
		ar[aa][i]=ar[bb][i]=ar[cc][i]=c;
	}
}
void paintVert(int c,int y){
	int aa=y!=1?y-1:1;
	int bb=y;
	int cc=y!=m?y+1:m;
	for(int i=1;i<=n;i++){
		ar[i][aa]=ar[i][bb]=ar[i][cc]=c;
	}
}
double dis(int x1,int y1,int x2,int y2){
	int dx=x1-x2;
	int dy=y1-y2;
	return sqrt(dx*dx+dy*dy);
}
void paintRound(int c,int x,int y,int r){
	int sx=x-r;
	int sy=y-r;
	int ex=x+r;
	int ey=y+r;
	if(sx<1)sx=1;
	if(ex>n)ex=n;
	if(sy<1)sy=1;
	if(ey>m)ey=m;
	for(int i=sx;i<=ex;i++){
		for(int j=sy;j<=ey;j++){
			if(dis(x,y,i,j)<=r){
				ar[i][j]=c;
			}
		}
	}
}
void printBoard(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=ar[i][j];
			if(x==0)cout<<'x';
			if(x==1)cout<<'b';
			if(x==2)cout<<'r';
			else if(x!=0&&x!=1) cout<<c;
		}
		cout<<endl;
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>c>>x;
			paintHori(c,x);
		}
		if(a==2){
			cin>>c>>y;
			paintVert(c,y);
		}
		if(a==3){
			cin>>c>>x>>y>>r;
			paintRound(c,x,y,r);
		}
		//printBoard();
	}
	int blue=0,red=0,none=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=ar[i][j];
			if(x==0)none++;
			if(x==1)blue++;
			if(x==2)red++;
		}
	}
	cout<<blue<<' '<<red<<' '<<none<<endl;
	return 0;
}


