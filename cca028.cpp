#include <iostream>
using namespace std;

const int MOD = 998244353;
const int MX = 1001;
int ar[MX][MX];
bool roadblock[MX][MX];
int main(void) {
	ios::sync_with_stdio(false);
	int n, k, r;
	cin >> n >> k >> r;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		roadblock[a][b] = true;
	}
	ar[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (roadblock[i][j] || ar[i][j] > 0)
				continue;
			ar[i][j] = (ar[i - 1][j] + ar[i][j - 1]) % MOD;
		}
	}
	for (int i = 0; i < r; i++) {
		int c, d;
		cin >> c >> d;
		cout << ar[c][d] << endl;
	}
	return 0;
}
