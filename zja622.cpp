#include<iostream>
using namespace std;

string s[20];
int max(int a,int b){
	return a>b?a:b;
}
int main(void){
	ios::sync_with_stdio(false);
	int i;
	int mxl=0;
	for(i=1;s[i-1]!="END";i++){
		getline(cin,s[i]);
		mxl=max(mxl,s[i].length());
	}
	i-=2;
	for(int c=0;c<mxl;c++){
		for(int l=1;l<=i;l++){
			if(s[l].length()>c)
				cout<<s[l][c]<<"  ";
			else
				cout<<"   ";
		}
		cout<<endl;
	}
	return 0;
}


