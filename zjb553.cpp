#include<iostream>
using namespace std;

int main(void){
	cin.sync_with_stdio(false);
	int n;
	while(cin>>n){
		int cnt=0;
		while(n!=1){
			if(n%2==0)n/=2;
			else n=n*3+1;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}


