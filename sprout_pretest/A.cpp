#include<iostream>
#include<string>
using namespace std;

int n,ln;
int res[100];
bool accept[10];
bool backtrack(int x){
	if(x-ln>2)return false;
	if(x>=ln){
		int sum=0;
		for(int i=0;i<x;i++)
			sum=sum*10+res[i];
		if(sum>=n){
			cout<<sum<<endl;
			return true;
		}
	}
	for(int i=0;i<10;i++){
		if(accept[i]){
			res[x]=i;
			if(backtrack(x+1))break;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		cin>>n;
		ln=to_string(n).length();
		for(int i=0;i<10;i++){
			char c;
			cin>>c;
			accept[i]=c-'0';
		}
		backtrack(0);
	}
	return 0;
}


