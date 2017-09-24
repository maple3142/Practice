#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<int,int> m;
int main(void){
	ios::sync_with_stdio(false);
	int n;
	int mcnt=0,mval=0;
	while(cin>>n){
		if(n==0)break;
		m[n]++;
		if(m[n]>mcnt){
			mcnt=m[n];
			mval=n;
		}
		else if(m[n]==mcnt&&n<mval){
			mval=n;
		}
		cout<<mcnt<<" "<<mval<<endl;
	}
	return 0;
}


