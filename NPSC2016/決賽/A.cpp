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

#define MAX_N 100000000 + 10

ll property[ MAX_N ];

int main(void){
	ios::sync_with_stdio(false);
	ll N, L, U;
	cin >> N >> L >> U;
	int cnt=0;
	for( ll i = 0; i < N; ++i ) {
		cin>> property[ i ];
		for( ll j = 0; j < i; ++j ) {
			ll dx, dy;
			dx = j - i;
			dy = property[ j ] - property[ i ];
			double x = abs( dy/dx );
			if( L <= x && x < U ) {
				cnt++;
			} 
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}

