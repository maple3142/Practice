#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct queen{
	int x,y;
	queen(int a,int b){
		x=a;
		y=b;
	}
};
int abs(int n){
	return (n<0?-1*n:n);
}
bool fQueen(int sx,int sy,int n){
		int putQueens=1;
		vector<queen> v;
		v.push_back(queen(sx,sy));
		for(int y=0;y<n;y++){
			for(int x=0;x<n;x++){
				bool placeable=true;
				for(queen q:v){
					if(x==q.x || y==q.y || abs(x-q.x)==abs(y-q.y)){
						placeable=false;
						break; 
					}
				}
				if(!placeable)continue;
				else{
					v.push_back(queen(x,y));
					putQueens++;
				}
			}
		}
		bool board[n][n]={};
		memset(board,0,sizeof(board));
		if(putQueens==n){
			for(queen q:v){
				board[q.x][q.y]=true;
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<(board[i][j]?"Q":"x");
				}
				cout<<endl; 
			}
			cout<<endl;
		}
		return (putQueens==n);
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		if(n==0)break;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cnt+=fQueen(i,j,n);
			}
		}
		cout<<endl<<cnt<<endl;
	}
	return 0;
}


