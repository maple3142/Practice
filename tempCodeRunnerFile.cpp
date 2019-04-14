#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

const ll MOD = 998224350;
int up[1001], down[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, r;
		cin >> n >> r;
		r = min(r, n - r);
		for (int i = 0; i < r; i++) {
			up[i] = n - i;
			down[i] = i + 1;
		}
		for (int i = 0; i < r; i++) {
			if (down[i] == 1)
				break;
			for (int j = 0; j < r; j++) {
				int g = __gcd(down[i], up[j]);
				if (g > 1) {
					down[i] /= g;
					up[j] /= g;
				}
				if (down[i] == 1)
					break;
			}
		}
		ll ans = 1;
		for (int i = 0; i < r; i++) {
			ans = (ans * up[i]) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
