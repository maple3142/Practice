#include<iostream>
using namespace std;

int cnt[26];
int main(void){
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		cnt[s[i]-'a']++;
	}
	int mx=0;
	for(int i=0;i<26;i++){
		mx=max(mx,cnt[i]);
	}
	cout<<len-mx<<endl;
	return 0;
}

