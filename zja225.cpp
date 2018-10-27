#include<iostream>
#include<algorithm>
using namespace std;

int ar[1000];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n,[](int a,int b){
			if(a%10==b%10){
				return a>b;
			}
			return a%10<b%10;
		});
		for(int i=0;i<n;i++){
			cout<<ar[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

