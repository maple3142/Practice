#include<iostream>
#include<stack>
using namespace std;

struct pic{
	int first;
	char second,third;
	pic(){
	}
	pic(int a,char b,char c){
		first=a;
		second=b;
		third=c;
	}
};
struct Result{
	char t,c;
	int x;
	Result(char a,int b,char d){
		t=a;
		x=b;
		c=d;
	}
};

const int MX=1505;

int n,m;
char ar[MX][MX];
pic findLine(){
	for(int i=1;i<=m;i++){
		bool isline=true;
		bool allstar=true;
		char c;
		for(int j=2;j<=n;j++){
			if(ar[j-1][i]!=ar[j][i]&&ar[j-1][i]!='*'&&ar[j][i]!='*'){
				isline=false;
			}
			else if(ar[j][i]!='*')c=ar[j][i];
			if(ar[j][i]!='*')allstar=false;
		}
		if(isline&&!allstar)return pic(i,'c',c);
	}
	for(int i=1;i<=n;i++){
		bool isline=true;
		bool allstar=true;
		char c;
		for(int j=2;j<=m;j++){
			if(ar[i][j-1]!=ar[i][j]&&ar[i][j-1]!='*'&&ar[i][j]!='*'){
				isline=false;
			}
			else if(ar[i][j]!='*')c=ar[i][j];
			if(ar[i][j]!='*')allstar=false;
		}
		if(isline&&!allstar)return pic(i,'r',c);
	}
	return pic(-1,'x','x');
}
void printGraph(){
	cout<<"====================="<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ar[i][j];
		}
		cout<<endl;
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ar[i][j];
		}
	}
	if(n==1){
		cout<<"row 1 z"<<endl;
		for(int i=1;i<=m;i++){
			cout<<"column "<<i<<' '<<ar[1][i]<<endl;
		}
	}
	else{
		stack<Result> stk;
		pic r;
		while(true){
			r=findLine();
			if(r.first==-1)break;
			if(r.second=='r'){
				stk.emplace('r',r.first,r.third);
				for(int i=1;i<=m;i++){
					ar[r.first][i]='*';
				}
			}
			if(r.second=='c'){
				stk.emplace('c',r.first,r.third);
				for(int i=1;i<=n;i++){
					ar[i][r.first]='*';
				}
			}
			//printGraph();
		}
		int remain=n+m-stk.size();
		while(remain--){
			cout<<"row 1 z"<<endl;
		}
		while(!stk.empty()){
			Result r=stk.top();
			stk.pop();
			if(r.t=='c')cout<<"column ";
			if(r.t=='r')cout<<"row ";
			cout<<r.x<<' '<<r.c<<endl;
		}
	}
	return 0;
}


