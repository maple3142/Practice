#include<iostream>
#include<list>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int m;
		cin>>m;
		string s;
		cin>>s;
		int n=0,len=s.length();
		for(char c:s){
			if(c=='(')n++;
			else n--;
			if(n==-1){
				n=0;
				cout<<'(';
			}
			cout<<c;
		}
		cout<<string(n,')')<<endl;
	}
	return 0;
}

