#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	string t;
	set<string> s;
	while(cin>>t){
		s.insert(t);
	}
	set<string> v;
	for(string x:s){
		for(int i=0;i<x.size();i++){
			int len=x.size()-i;
			if(s.find(x.substr(0,i))!=s.end()&&s.find(x.substr(i,len))!=s.end()){
				v.insert(x);
			}
		}
	}

	for(string x:v){
		cout<<x<<endl;
	}
	return 0;
}

