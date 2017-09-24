#include<iostream>
using namespace std;

int main(void){
	string str,mky;
	while(cin>>str>>mky){
		int sid,mid;
		for(sid=0,mid=0;mid<mky.length();mid++){
			if(str[sid]==mky[mid])
				sid++;
			
		}
		cout<<(sid==str.length()?"YES":"NO")<<endl;
	}
	return 0;
}


