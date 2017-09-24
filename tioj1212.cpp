#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool ok[501][501];
int d[501][501];
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		if(n==m&&m==0)break;
		memset(d,0x3f,sizeof(d));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			ok[a][b]=true;
			d[a][b]=1;
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				for(int i=1;i<=n;i++){
					if(d[i][j]>d[i][k]+d[k][j]){
						d[i][j]=d[i][k]+d[k][j];
					}
				}
			}
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			mn=min(d[i][i],mn);
		}
		cout<<(mn==0x3f3f3f3f?0:mn)<<endl;
	}
	return 0;
}

