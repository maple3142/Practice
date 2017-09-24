#include<iostream>
using namespace std;

int n,m;
int res[10]={};
void backtracking(int x){
	if(x==n){
		for(int i=0;i<n;i++)
			cout<<res[i];
		cout<<endl;
		return;
	}
	for(int i=0;i<=m;i++){
		res[x]=i;
		backtracking(x+1);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		backtracking(0);
	}
	return 0;
}


