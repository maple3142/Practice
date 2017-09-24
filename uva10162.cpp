#include<iostream>
using namespace std;

int seq[]={0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};
int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		int len=s.length();
		if(len==1&&s[0]=='0')break;
		int n=s[len-1]-'0';
		if(len>1)
			n+=(s[len-2]-'0')*10;
		cout<<(seq[n%20]+n/20*4)%10<<endl;
	}
	return 0;
}

