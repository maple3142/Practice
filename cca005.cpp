#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MX=1000005;
bool prime[MX];
void init(){
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<sqrt(MX);i++){
		if(prime[i]){
			for(int k=i+i;k<MX;k+=i){
				prime[k]=false;
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	init();
	int n;
	cin>>n;
	cout<<(prime[n]?"YES":"NO")<<endl;
	return 0;
}

