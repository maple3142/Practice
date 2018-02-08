#include<iostream>
using namespace std;

int ar[1000001];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		int sum=0;
		for(int i=1;i<n;i++){
			int mx=0;
			for(int j=i+1;j<=n;j++){
				if(mx<=ar[i]&&mx<=ar[j]){
					sum++;
				}
				mx=max(mx,ar[j]);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

