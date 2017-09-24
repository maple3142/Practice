#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
using namespace std;

bool tree[81][81]={};
bool vis[81][81]={};
bool isTree=true;
int dx,dy;
void tok(string s){
	string s1,s2;
	bool toS2=false;
	for(char i:s){
		if(i>='0' && i<='9'){
			if(toS2){
				s2+=i;
			}
			else{
				s1+=i;
			}
		}
		else
			toS2=true;
	}
	int n1=stoi(s1),n2=stoi(s2);
	tree[n1][n2]=true;
	tree[n2][n1]=true;
	dx=n1;
	dy=n2;
}
void DFS(int x,int y){
	vis[x][y]=true;
	
}
int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		cin.ignore(100,'\n');
		string s;
		for(int i=0;i<n;i++){
			getline(cin,s);
			stringstream ss;
			ss<<s;
			while(!ss.eof()){
				ss>>s;
				tok(s);
			}
			DFS(dx,dy);
			cout<<(isTree?"T":"F")<<endl;
		}
	}
	return 0;
}


