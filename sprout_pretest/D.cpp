#include<iostream>
#include<cstring>
using namespace std;

int sccnt[150]={};
int tccnt[150]={};
int main(void){
	ios::sync_with_stdio(false);
	string s,t;
	while(cin>>s>>t){
		if(s.length()!=t.length())
			cout<<"No"<<endl;
		else{
			for(char c:s){
				sccnt[c]++;
			}
			for(char c:t){
				tccnt[c]++;
			}
			int i;
			for(i='a';i<='z';i++){
				if(sccnt[i]!=tccnt[i]){
					cout<<"No"<<endl;
					break;
				}
			}
			if(i>='z')
				cout<<"Yes"<<endl;
		}
		memset(sccnt,0,sizeof(sccnt));
		memset(tccnt,0,sizeof(tccnt));
	}
	return 0;
}


