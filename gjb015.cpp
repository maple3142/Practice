#include<iostream>
#include<sstream>
using namespace std;

int main(void){
	string s;
	stringstream ss;
	bool end=false;
	int line,index;
	for(int i=0;i<3;i++){
		getline(cin,s);
		ss<<s;
		int j=0;
		while(!ss.eof()){
			string x;
			ss>>x;
			if(x=="BILL"){
				line=i+1;
				index=j+1;
				end=true;
				break;
			}
			j++;
		}
		ss.clear();
	}
	if(end)
		cout<<line<<" "<<index<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}


