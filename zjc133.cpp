#include<iostream>
using namespace std;

const int EMPTY=1;
const int WALL=2;
const int ROOK=3;

int n,ans=0;
int board[5][5];
bool isPlaceable(int x,int y){
	if(board[x][y]!=EMPTY)return false;
	for(int i=x;i<=n;i++){
		if(board[i][y]==WALL)break;
		if(board[i][y]==ROOK)return false;
	}
	for(int i=x;i>=1;i--){
		if(board[i][y]==WALL)break;
		if(board[i][y]==ROOK)return false;
	}
	for(int i=y;i<=n;i++){
		if(board[x][i]==WALL)break;
		if(board[x][i]==ROOK)return false;
	}
	for(int i=y;i>=1;i--){
		if(board[x][i]==WALL)break;
		if(board[x][i]==ROOK)return false;
	}
	return true;
}
bool isAllUnplaceable(int x){
	for(int i=1;i<=n;i++){
		if(board[x][i]==EMPTY && isPlaceable(x,i))return false;
	}
	return true;
}
int countRook(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(board[i][j]==ROOK)cnt++;
		}
	}
	return cnt;
}
void bt(int deep=1){
	if(deep>n)return;
	if(isAllUnplaceable(deep))bt(deep+1);
	for(int i=1;i<=n;i++){
		if(isPlaceable(deep,i)){
			board[deep][i]=ROOK;
			
			ans=max(ans,countRook());
			bt(deep);
			
			board[deep][i]=EMPTY;
		} 
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		if(n==0)break;
		char c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c;
				if(c=='X')board[i][j]=WALL;
				else board[i][j]=EMPTY;
			}
		}
		bt();
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

