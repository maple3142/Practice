#include<iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int x=0;
		int cnt=0;
		for(char c:s){
			if(c=='('){
				x++;
			}
			if(c==')'){
				x--;
				cnt++;
			}
			if(x<0)cnt=-0x3f3f3f3f;
		}
		if(x!=0)cnt=-0x3f3f3f3f;
		if(cnt<0)cnt=0;
		cout<<cnt<<endl;
	}
	return 0;
}

