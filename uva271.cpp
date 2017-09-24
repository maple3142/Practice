#include<iostream>
using namespace std;

bool ok(string s){
	int cnt=0;
	for(int i=s.length()-1;i>=0;i--){
		char c=s[i];
		if('p'<=c && c<='z')cnt++;
		else if(c=='N'){
			if(cnt==0)return false; 
		}
		else if(c=='C'||c=='D'||c=='E'||c=='I'){
			if(cnt<=1)return false;
			cnt--;
		}
		else return false;
	}
	return (cnt==1);
}
int main(void){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		cout<<(ok(s)?"YES":"NO")<<endl;
	}
	return 0;
}

