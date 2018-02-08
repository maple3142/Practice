#include<stdio.h>
#include<string.h>

char c;
int n;
int cnt[3];
short board[502][502];
bool vis[502][502];
int X[]={1,1,0,-1,-1,-1,0,1};
int Y[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y,int d=1){
	if(x==0||y==0||x>n||y>n)return;
	short cur=board[x][y];
	vis[x][y]=true;
	bool no=true;
	for(int i=0;i<8;i++){
		if(vis[x+X[i]][y+Y[i]]||board[x+X[i]][y+Y[i]]!=cur)continue;
		dfs(x+X[i],y+Y[i],d+1);
		no=false;
	}
	if(no&&d==5)cnt[cur]++;;
	if(d>=5)printf("%d %c %d\n",d,'a'+cur,no);
}
int main(void){
	while(scanf("%d",&n)!=-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf(" %c",&c);
				if(c=='A')c=0;
				if(c=='B')c=1;
				if(c=='C')c=2;
				if(c=='.')c=3;
				board[i][j]=c;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(vis[i][j]||board[i][j]==3)continue;
				dfs(i,j);
			}
		}
		for(int i=0;i<3;i++){
			printf("%c %d\n",'a'+i,cnt[i]);
			cnt[i]=0;
		}
		puts("");
	}
	return 0;
}
/*
10
...AAAAA..
...C......
.B..C.....
.B...C....
.B....C...
.B.....C.A
.B......A.
.......A..
......A...
.....A....
*/

