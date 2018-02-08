#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long int ll;
#define MAX_N 1000000 + 10
int num[ MAX_N ];
ll n;
ll result=0,sum=0,lasti=0;
void x(ll i){
	if(i>=n)return;
	sum += num[i];
	if( sum < 0 ){
		result += (i-lasti+1) * (n-i);
		lasti = i+1;
		sum = 0;
	}
	else if(num[i]<0){
		result+=(n-i);
	}
	x(i+1);
}
int main(void){
	ios::sync_with_stdio(false);
	cin >> n;
	for( int i = 0; i < n; ++i ) {
		cin>>num[i];
	}
	x(0);
	/*for( int i = 0; i < n; ++i ) {
		sum += num[i];
		if( sum < 0 ){
			result += (i-lasti+1) * (n-i);
			lasti = i;
			sum = 0;
		}
		else if(num[i]<0){
			result++;
		}
	}*/
	cout << result << endl;
//	int cnt=0,sum=0,sumcnt=0;
//	for(int i=0;i<n;i++){
//		sum+=num[i];
//		sumcnt+1;
//		if(sum<0){
//			cnt+=(n-i)*(1+sumcnt)/2;
//			sum=0;
//			sumcnt=0;
//		}
//	}
//	cout<<cnt<<endl;
	return 0;
}

