#include<iostream>
using namespace std;

int main(void){
	double n,m;
	while(cin>>n>>m){
		double b=0;
		for(double h=1;b<n;h++){
			b=(1+(1+(h-1)*m))*h/2;
		}
		cout<<(n==b?"Go Kevin!!":"No Stop!!")<<endl;
	}
	return 0;
}


