#include <iostream>
using namespace std;
typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		ll n, sum;
		cin >> n;
		sum = n;
		while (n >= 6) {
			ll x = n / 6;
			sum += x;
			n %= 6;
			n += x;
		}
		cout << sum << ' ' << n << endl;
	}
	return 0;
}
