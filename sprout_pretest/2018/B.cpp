#include<iostream>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;

vector<string> split(const string &s,char c){
	vector<string> result;
	stringstream ss(s);
	string tok;
	while(getline(ss,tok,c)){
		result.push_back(tok);
	}
	return result;
}
string lower(const string &s){
	string x=s;
	for(int i=0;i<x.length();i++){
		if(x[i]<='Z'&&x[i]>='A')x[i]=x[i]+'a'-'A';
		else x[i]=x[i];
	}
	return x;
}
int main(void){
	ios::sync_with_stdio(false);
	int n,y;
	cin>>n>>y;
	string s;
	cin.ignore(1000,'\n');
	while(n--){
		getline(cin,s);
		vector<string> v=split(s,',');
		cout<<"Name: "<<v[0]<<endl;
		cout<<"Account: "<<lower(v[1])<<endl;
		cout<<"Class: "<<setfill('0')<<setw(2)<<stoi(v[2])<<endl;
		cout<<"Age: "<<y-stoi(v[3])<<endl;
		cout<<endl;
	}
	return 0;
}

