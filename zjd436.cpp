#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		sort(s.begin(),s.end());
		do{
			cout<<s<<endl;
		}while(next_permutation(s.begin(),s.end()));
		cout<<endl;
	}
	return 0;
}

