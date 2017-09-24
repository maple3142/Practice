#include<iostream>
using namespace std;

int main(void){
	int y,m;
	while(cin>>y>>m){
		int x=y*12+m;
		if(x<=1087 || x>=1220)
			x=1087;
		cout<<x-1087<<endl;
	}
	return 0;
}


