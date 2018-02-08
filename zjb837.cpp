#include<iostream>
using namespace std;

int f[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269};
int main(void){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		int cnt=0;
		for(int n:f){
			if(n>=a && n<=b){
				cout<<n<<endl;
				cnt++;
			}
		}
		cout<<cnt<<endl;
		if(T>=1)cout<<"------"<<endl;
	}
	return 0;
}

