#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	int n;
	while(cin>>n){
		string s[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		sort(s,s+n);
		for(int i=0;i<n;i++)
			cout<<s[i]<<endl;
	}
	return 0;
}


