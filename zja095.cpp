#include<iostream>
using namespace std;

int main(void){
	cin.sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		cout<<m+!(n==m)<<endl;
	}
	return 0;
}


