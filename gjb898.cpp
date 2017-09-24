#include<iostream>
using namespace std;

bool AbigB(string a,string b){
	int al=a.length(),bl=b.length();
	if(al>bl)return true;
	else if(al<bl)return false;
	else{
		int ml=(al<bl?al:bl);
		for(int i=0;i<ml;i++){
			if(a[i]>b[i])return true;
			if(a[i]<b[i])return false;
		}
	}
	return false;
}
int main(void){
	cin.sync_with_stdio(false);
	int n;
	cin>>n;
	for(int u=0;u<n;u++){
		string mx="0";
		for(int i=0;i<3;i++){
			string x;
			cin>>x;
			if(AbigB(x,mx))mx=x;
		}
		cout<<mx<<endl;
	}
	return 0;
}


