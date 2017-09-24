#include<iostream>
#include<cmath>
using namespace std;

bool sieve[100000];
void init(){
	sieve[0]=sieve[1]=true;
	int s=sqrt(100000);
	for(int i=0;i<s;i++)
		if(!sieve[i])
			for(int j=i+i;j<100000;j+=i)
				sieve[j]=true;
}
int main(void){
	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cout<<(sieve[x]?"N":"Y")<<endl;
	}
	return 0;
}


