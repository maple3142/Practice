#include<iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		string r=s;
		for(int j=0;j<s.length();j++){
			r[j]=(s[j]+3-'A')%26+'A';
		}
		cout<<r<<endl;
	}
	return 0;
}


