#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		cout<<s;
		for(int i=s.length()-2;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}


