#include<iostream>
#include<algorithm>
using namespace std;

char low(char c){
	if(c<=90)
		c+=32;
	return c;
}
bool charcp(char a,char b){
	char la=low(a),lb=low(b);
	if(la==lb)return a<b;
	else return la<lb;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		sort(s.begin(),s.end(),charcp);
		do{
			cout<<s<<endl;
		}while(next_permutation(s.begin(),s.end(),charcp));
	}
	return 0;
}

