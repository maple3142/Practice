#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool ar[50][50],vis[50][50];
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};
int cnt;
void DFS(int a,int b,int num){
	//printf("%d %d %d\n",a,b,num);
	vis[a][b] = true;
	cnt = num;
	int wall = 0;
	for(int i=0;i<4;i++){
		if(!ar[a+X[i]][b+Y[i]]){
			wall++;
		}
	}
	if(wall >= 3){
		cnt = 0;
		return;
	}
	for(int i=0;i<4;i++){
		if(ar[a+X[i]][b+Y[i]] && !vis[a+X[i]][b+Y[i]]){
			DFS(a+X[i],b+Y[i],num+1);
		}
	}
}
int main(void){
    int n,m,a=0,jia=0;
    unsigned long long int chen=1;
    char c,trash;
	scanf("%d %d",&n,&m);
	memset(ar,0,sizeof(ar));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		while(c = getchar())if(c != ' ' && c != '\n')break;
    		if(c == '.')ar[i][j] = true;
		}
	}
	/*for(int i=0;i<=n+1;i++){
    	for(int j=0;j<=m+1;j++){
    		printf("%d",ar[i][j]);
		}
		printf("\n");
	}*/
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j] || !ar[i][j])continue;
			cnt = 0;
			DFS(i,j,1);
			if(cnt!=0){
				a++;
				jia+=cnt;
				chen*=cnt;
			}
		}
	}
	printf("%d %d %llu\n",a,jia,chen);
	return 0;
}


