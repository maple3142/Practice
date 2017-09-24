#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

int main(void){
	string a,b,c;
	while(cin>>a>>b>>c){
		stringstream ss;
		unsigned long long int n[6];
		ss<<a<<b<<c;
		ss>>n[0];
		ss.clear();
		ss<<a<<c<<b;
		ss>>n[1];
		ss.clear();
		ss<<b<<a<<c;
		ss>>n[2];
		ss.clear();
		ss<<c<<b<<a;
		ss>>n[3];
		ss.clear();
		ss<<c<<a<<b;
		ss>>n[4];
		ss.clear();
		ss<<b<<c<<a;
		ss>>n[5];
		ss.clear();
		priority_queue<unsigned long long int> q;
		for(int i=0;i<6;i++){
			q.push(n[i]);
		}
		cout<<q.top()<<endl;
	}
	return 0;
}


