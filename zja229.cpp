#include<iostream>
using namespace std;

int N;
bool ar[10000];
void print(int x=0,int op=0,int cl=0){
	if(x>=N*2){
		for(int i=0;i<2*N;i++){
			cout<<(ar[i]?'(':')');
		}
		cout<<'\n';
		return;
	}
	if(op<N){
		ar[x]=true;
		print(x+1,op+1,cl);
	}
	if(op>cl){
		ar[x]=false;
		print(x+1,op,cl+1);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>N){
		print();
		cout<<'\n';
	}
	return 0;
}

