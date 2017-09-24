#include<iostream>
using namespace std;

int n;
int res[8]={};
bool used[8]={};
void backtracking(int x){
	if(x==n){
		for(int i=0;i<n;i++)
			cout<<res[i];
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			res[x]=i;
			backtracking(x+1);
			used[i]=false;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>n){
		backtracking(0);
	}
	return 0;
}


