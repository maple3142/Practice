#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int a,b;
	while(cin>>a>>b){
		if(a==b){
			cout<<"yiping"<<endl;
		}
		else{
			cout<<"kelvin"<<endl;
		}
	}
	return 0;
}

