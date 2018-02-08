#include<iostream>
#include<vector>
using namespace std;

const int MX=10005;
bool notprime[MX];
int main(void){
	ios::sync_with_stdio(false);
	notprime[0]=notprime[1]=true;
	for(int i=2;i<=MX;i++){
		if(!notprime[i]){
			for(int j=i*2;j<=MX;j+=i){
				notprime[j]=true;
			} 
		}
	}
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> v;
	for(int i=a;i<=b;i++)if(!notprime[i])v.push_back(i);
	if(v.size()==0){
		cout<<0<<endl;
	}
	else if(v.size()<=2*c){
		for(int x:v)cout<<x<<' ';
		cout<<endl;
	}
	else{
		for(int i=0;i<c;i++){
			cout<<v[i]<<' ';
		}
		for(int i=v.size()-c;i<v.size();i++){
			cout<<v[i]<<' ';
		}
	}
	return 0;
}

