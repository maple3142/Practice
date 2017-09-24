#include<iostream>
#define endl '\n'
using namespace std;

int seq[16]={0,5,8,8,2,3,5,2,9,4,1,1,7,6,4,7};
int main(void){
	cin.sync_with_stdio(false);
	int n;
	cin>>n;
	for(int u=0;u<n;u++){
		int x;
		cin>>x;
		int sum=0;
		for(int i=0;i<x;i++)
			sum+=seq[i%16];
		cout<<sum-seq[x%16-(x%16!=0)]<<" "<<sum<<endl;
	}
	return 0;
}


