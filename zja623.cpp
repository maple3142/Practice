#include<iostream>
using namespace std;

int f(int n){
	int s=1;
	for(int i=2;i<=n;i++)
		s*=i;
	return s;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		cout<<f(n)/(f(m)*f(n-m))<<endl;
	}
	return 0;
}


