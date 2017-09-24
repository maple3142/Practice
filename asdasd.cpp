#include<iostream>
using namespace std;

int getzero(int n){
	int zero=0;
	while(n%5==0){
		n/=5;
		zero++;
	}
	return zero;
}
int main(void){
	int q;
	cin>>q;
	int n[q];
	for(int i=0;i<q;i++)
		cin>>n[i];
	
	for(int i=0;i<q;i++){
		
	}
	return 0;
}


