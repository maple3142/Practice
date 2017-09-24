#include<iostream>
using namespace std;

int x[100000000]={0};
int main(void){
	int n;
	while(cin>>n){
		int mx=0,mxidx=0;
		for(int i=0;i<n;i++){
			int d;
			cin>>d;
			x[d]++;
			if(x[d]>mx){
				mx=x[d];
				mxidx=d;
			}
		}
		cout<<mxidx<<" "<<mx<<endl;
	}
	return 0;
}
