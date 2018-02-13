#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

struct token{
	int num=0;
	bool isX=false;
};
vector<token> toTokens(const string &str){
	string s=str,tmp;
	if(s.front()!='-')s='+'+s;
	vector<token> v;
	int lst=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='+'||s[i]=='-'){
			if(tmp.length()>0){
				token t;
				if(tmp.back()=='x'){
					t.isX=true;
					tmp=tmp.substr(0,tmp.length()-1);
				}
				if(tmp.length()==1)tmp=tmp+"1";
				t.num=stoi(tmp);
				v.push_back(t);
			}
			tmp.clear();
		}
		tmp+=s[i];
	}
	if(tmp.length()>0){
		token t;
		if(tmp.back()=='x'){
			t.isX=true;
			tmp=tmp.substr(0,tmp.length()-1);
		}
		if(tmp.length()==1)tmp=tmp+"1";
		t.num=stoi(tmp);
		v.push_back(t);
	}
	return v;
}
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
		string line,left,right;
		getline(cin,line);
		istringstream iss(line);
		getline(iss,left,'=');
		getline(iss,right,'=');
		
		pii l,r;
		vector<token> lt=toTokens(left),rt=toTokens(right);
		for(token tok:lt){
			if(tok.isX)l.second+=tok.num;
			else l.first+=tok.num;
		}
		for(token tok:rt){
			if(tok.isX)r.second+=tok.num;
			else r.first+=tok.num;
		}
		int n=l.first-r.first;
		int x=r.second-l.second;
		if(x==0&&n==0)cout<<"IDENTITY"<<endl;
		else if(x==0)cout<<"IMPOSSIBLE"<<endl;
		else{
			double ans=(double)n/x;
			//cout<<n<<' '<<x<<endl;
			if(ans>=0||(int)ans==ans)cout<<(int)ans<<endl;
			else cout<<(int)ans-1<<endl;
		}
	}
	return 0;
}

