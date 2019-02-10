#include<iostream>
using namespace std;

const int MX=2000005;
bool ar[MX];
int main(void){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n;
	while(n--){
		cin>>k;
		ar[k]=!ar[k];
	}
	for(int i=0;i<MX;i++){
		if(ar[i]){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

