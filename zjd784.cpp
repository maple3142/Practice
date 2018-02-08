#include<iostream>
using namespace std;

int ar[101];
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
			ar[i]+=ar[i-1];
		}
		int mx=-10001;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				mx=max(mx,ar[j]-ar[i-1]);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}

