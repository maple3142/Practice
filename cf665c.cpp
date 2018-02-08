#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=1;i<s.length();i++){
		if(s[i]==s[i-1]){
			s[i]='a';
			while(s[i]==s[i-1] || (i+1<s.length()&&s[i]==s[i+1]))s[i]++;
		}
	}
	cout<<s<<endl;
	return 0;
}

