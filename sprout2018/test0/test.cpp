#include<iostream>
using namespace std;

char ar[10000][10000];
int main(void){
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	string s;
	int x;
	char c;
	while(cin>>s>>x>>c){
		if(s=="row"){
			for(int i=1;i<=n;i++){
				ar[x][i]=c;
			}
		}
		if(s=="column"){
			for(int i=1;i<=m;i++){
				ar[i][x]=c;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<ar[i][j];
		}
		cout<<endl;
	}
	return 0;
}


