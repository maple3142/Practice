#include<iostream>
#include<cmath>
using namespace std;

int getn(int n){
	int x=n;
	int cnt=0;
	while(n!=1){
		n/=2;
		cnt++;
	}
	return pow(2,cnt);
}//1 2 2 4 4 4 4 8 8 8 8 8 8 8 8
int main(void){
	ios::sync_with_stdio(false);
	int sum=0,th=0,i=0,n;
	start:
	while(cin>>n){
		if(n==0)break;
		sum+=n;
		th+=getn(n);
		i++;
	}
	if(i!=0){
		cout<<th<<endl;
		sum=th=i=0;
		goto start;
	}
	return 0;
}


