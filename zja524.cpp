#include<iostream>
using namespace std;

int N;
bool used[9];
int ar[9];
int print(int lv=0){
	if(lv==N){
		for(int i=0;i<N;i++){
			cout<<ar[i];
		}
		cout<<'\n';
	}
	for(int i=N;i>=1;i--){
		if(used[i])continue;
		used[i]=true;
		ar[lv]=i;
		print(lv+1);
		used[i]=false;
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>N){
		print();
	}
	return 0;
}

