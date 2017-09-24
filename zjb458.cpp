#include<iostream>
#include<cmath>
using namespace std;

int main(void){
	cin.sync_with_stdio(false);
	int T;
	while(cin>>T){
		int w,h;
		while(cin>>w>>h){
			cout<<w<<" "<<h<<endl;
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					int r,g,b;
					cin>>r>>g>>b;
					int rd=(r+g+b)/3.0;
					if(rd>=T)rd=255;
					else rd=0;
					cout<<rd<<" "<<rd<<" "<<rd<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}


