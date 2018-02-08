#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int ll;

#define MAX_N 99999999
#define INF 1000000000 + 10

//int factors[ MAX_N ][ 2 ], 
int first_cut = 0;
map<ll, ll> factors1;
map<ll, ll> factors2;

int factor( ll n ) {
	if( !factors1[ n ] ) {
		for( ll i = sqrt( n ); n >= 1; --i ) {
			if( n % i == 0 ) {
				factors1[ n ] = i;
				factors2[ n ] = n/i;
				break;
			}
		}
	}
	return factors1[ n ] + factors2[ n ];
}

void f( ll n ) {
	ll min = INF;
	for( ll i = sqrt( n ); i >= 1; --i ) {
		if( n % i == 0 ) {
			ll value = factor( n/i ) + i;
			if( value < min ) {
				min = value;
				first_cut = i;
			}
		}
	}
//	return min;
}

int main(void){
	ios::sync_with_stdio(false);
	ll N;
	cin >> N;
    f( N );
    ll a = first_cut, b = factors1[ N/first_cut ], c = factors2[ N/first_cut ];
	ll x[3] = { a, b, c };
	sort( x, x+3 );
	a = x[0]; b = x[1]; c = x[2];
	cout << 2*( a*b + b*c + a*c ) << " " << a << " " << b << " " << c << endl;
	return 0;
}

