#include <iostream>
using namespace std;
typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		ll r, l, n;
		cin >> r >> l >> n;
		ll d = r - l;
		if (n % 2 == 0) {
			cout << n / 2 * d << endl;
		} else {
			cout << n / 2 * d + r << endl;
		}
	}
	return 0;
}
