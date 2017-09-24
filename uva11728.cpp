#include<iostream>
using namespace std;

int ar[10001];
int fac(int n){
	int sum=0;
	for(int i=1;i<=n;i++)
		if(n%i==0)
			sum+=i;
	return sum;
}
int main(void){
	ios::sync_with_stdio(false);
	for(int i=1;i<=1000;i++){
		if(ar[i]==0)ar[i]=-1;
		ar[fac(i)]=i;
	}
	int n,cse=1;
	while(cin>>n&&n!=0){
		cout<<"Case "<<cse++<<": "<<ar[n]<<endl;
	}
	return 0;
}

