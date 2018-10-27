#include<iostream>
#include<cstring>
using namespace std;

int ar[26];
string s;
int main(void){
	ios::sync_with_stdio(false);
	while(cin>>s){
		int len=s.length();
		for(int i=0;i<len;i++){
			char c=s[i];
			if('a'<=c&&c<='z'){
				ar[c-'a']++;
			}
			else if('A'<=c&&c<='Z'){
				ar[c-'A']++;
			}
		}
		int oddcnt=0;
		for(int i=0;i<26;i++){
			if(ar[i]%2==1){
				oddcnt++;
			}
		}
		cout<<(oddcnt>1?"no...":"yes !")<<endl;
		memset(ar,0,sizeof(ar));
	}
	return 0;
}

