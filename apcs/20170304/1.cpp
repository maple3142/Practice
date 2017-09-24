#include<iostream>
using namespace std;

int abs(int a){
	return a>0?a:-a;
}
int main(void){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	
	int e=0,o=0;
	for(int i=0;i<s.length();i++){
		if(i%2)e+=s[i]-'0';
		else o+=s[i]-'0';
	}
	cout<<abs(o-e)<<endl;
	return 0;
}

