#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long int ll;

int ar[1000005];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cin>>ar[0];
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		ar[i]=ar[i-1]+x;
	}
	for(int i=0;i<n;i++)cout<<ar[i]<<" ";
	cout<<endl;
	int bad=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<i<<" "<<j<<" "<<ar[j]-ar[i]<<endl;
			if(ar[j]-ar[i]<0){
				bad+=n-j;
				break;
			}
		}
	}
	cout<<bad<<endl;
	return 0;
}

