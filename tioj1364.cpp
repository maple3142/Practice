#include<iostream>
#include<algorithm>
using namespace std;

int ar[1000010];
bool comp(int a,int b){
	return a>b;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k){
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n,comp);
		cout<<ar[k-1]<<endl;
	}
	return 0;
}


