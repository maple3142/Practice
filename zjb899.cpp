#include<iostream>
#include<cmath>
using namespace std;

int xc[101];
int yc[101];
int findmaxidx(int ar[101]){
	int mx=0,mxidx=0;
	for(int i=1;i<101;i++){
		if(mx<ar[i]){
			mx=ar[i];
			mxidx=i;
		}
	}
	return mxidx;
}
int main(void){
	ios::sync_with_stdio(false);
	int x,y;
	for(int i=0;i<3;i++){
		cin>>x>>y;
		xc[x]++;
		yc[y]++;
	}
	cout<<findmaxidx(yc)<<" "<<findmaxidx(xc)<<endl;
	return 0;
}

