#include<iostream>
#include<unordered_map>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	unordered_map<string,string> m,mm;
	string s;
	while(cin>>s){
		string n,r;
		if(s=="add"){
			cin>>n>>r;
			m[n]=r;
			mm[r]=n;
		}
		if(s=="del"){
			cin>>n;
			if(n[0]=='n'){
				n=n.substr(1,n.length()-1);
				mm.erase(m[n]);
				m.erase(n);
				
			}
			else{
				n=n.substr(1,n.length()-1);
				m.erase(mm[n]);
				mm.erase(n);
			}
		}
		if(s=="chk"){
			cin>>n;
			if(n[0]=='n'){
				n=n.substr(1,n.length()-1);
				if(m.count(n)){
					cout<<n<<" "<<m[n]<<endl;
				}
				else{
					cout<<"Not found."<<endl;
				}
			}
			else{
				n=n.substr(1,n.length()-1);
				if(mm.count(n)){
					cout<<mm[n]<<" "<<n<<endl;
				}
				else{
					cout<<"Not found."<<endl;
				}
			}
			
		}
	}
	return 0;
}

