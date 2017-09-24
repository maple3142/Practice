#include<iostream>
#include <sstream>
#include <string>
using namespace std;
string tostring(int n){
	stringstream ss;
	ss<<n;
	string str;
	ss>>str;
	ss.clear();
	return str; 
}
int main(void){
	string a,b;
	while(cin>>a>>b){
		stringstream sa(a);
		int mode=0,sum1=0;
		string sub_str;
		while(getline(sa,sub_str,':')){
			stringstream b;
			b<<sub_str;
			int n;
			b>>n;
			b.clear();
			if(mode==0){
				sum1+=n*3600;
				mode++;
			}
			else if(mode==1){
				sum1+=n*60;
				mode++;
			}
			else if(mode==2){
				sum1+=n;
				mode++;
			}
		}
		stringstream sb(b);
		mode=0;
		int sum2=0;
		while(getline(sb,sub_str,':')){
			stringstream b;
			b<<sub_str;
			int n;
			b>>n;
			b.clear();
			if(mode==0){
				sum2+=n*3600;
				mode++;
			}
			else if(mode==1){
				sum2+=n*60;
				mode++;
			}
			else if(mode==2){
				sum2+=n;
				mode++;
			}
		}
		int s=sum1-sum2;
		s=(s>=0?86400-s:-1*s);
		int h=0,m=0;
		if(s/60>=1){
			m+=s/60;
			s%=60;
		}
		if(m/60>=1){
			h+=m/60;
			m%=60;
		}
		
		string a,b,c;
		a=(h<10)?"0"+tostring(h):tostring(h);
		b=(m<10)?"0"+tostring(m):tostring(m);
		c=(s<10)?"0"+tostring(s):tostring(s);
		cout<<a<<":"<<b<<":"<<c<<endl;
	}
	return 0;
}


