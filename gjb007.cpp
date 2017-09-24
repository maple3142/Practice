#include<iostream>
using namespace std;

int main(void){
	string str;
	while(cin>>str){
		bool loop=true;
		if(str.length()%2==0){
			for(int i=0;i<str.length()/2;i++)
				if(str[i]!=str[str.length()-i-1]){
					loop=false;
					break;
				}
		}
		else{
			for(int i=0;i<str.length()/2;i++)
				if(str[i]!=str[str.length()-i-1]){
					loop=false;
					break;
				}	
		}
		cout<<(loop?"YES":"NO")<<endl;
	}
	return 0;
}


