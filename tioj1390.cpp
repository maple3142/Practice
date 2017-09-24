#include<iostream>
using namespace std;

int ar[16][16];
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>ar[i][j];
	}
	
	return 0;
}


