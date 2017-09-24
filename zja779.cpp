#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(getline(cin,s)){
		cout<<s<<endl;
		bool is=true;
		int symbol=0;
		for(int i=0;i<s.length()/2;i++){
			if(!((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')))
			
			if(s[i]!=s[s.length()-i])
				is=false;
		}
		cout<<(is?"-- is a palindrome":"-- is not a palindrome")<<endl;
	}
	return 0;
}


