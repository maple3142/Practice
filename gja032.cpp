#include<iostream>
#include<string>
#include<sstream> //for convert
using namespace std;

int main(void){
	string str;
	while(cin>>str){
		string a,b;
		int idx=0;
		while(str[idx]!='+' && str[idx]!='-' && str[idx]!='*'){
			a+=str[idx];
			idx++;
		}
		char oper=str[idx];
		idx++;
		while(idx<str.length()){
			b+=str[idx];
			idx++;
		}
		//int x=stoi(a),y=stoi(b); **c++11only,greenjudge use c++98**
		
		stringstream buf;  //a,b is string
		int x,y;
		buf<<a;
		buf>>x;
		buf.clear();
		buf<<b;
		buf>>y;  //c++98 used
		
		switch(oper){
			case '+':
				cout<<x+y<<endl;
				break;
			case '-':
				cout<<x-y<<endl;
				break;
			case '*':
				cout<<x*y<<endl;
				break;
		}
	} 
	return 0;
}


