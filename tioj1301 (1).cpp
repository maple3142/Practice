#include<iostream>
using namespace std;

int getn(int n){
	int cnt=0;
	while(n!=1){
		n/=2;
		cnt++;
	}
	return cnt;
}
int main(void){
	ios::sync_with_stdio(false);
	cout<<getn(8)<<endl;
	int sum=0,i=0,n;
	start:
	while(cin>>n){
		if(n==0)break;
		
		i++;
	}
	if(i!=0)goto start;
	return 0;
}


