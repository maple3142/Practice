#include<iostream>
using namespace std;
typedef long long int ll;

int main(void){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int cnt=1;
		while(n!=m){
			if(n>m){
				n-=m;
			}
			else{
				m-=n;
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

