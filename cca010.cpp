#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

const ll MOD = 998224350;
const int MX = 1005;
int ar[MX][MX];
int main(void) {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 1001; i++) {
		ar[i][1] = ar[i][i] = 1;
		for (int j = 2; j < i; j++) {
			ar[i][j] = (ar[i - 1][j - 1] + ar[i - 1][j]) % MOD;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int n, r;
		cin >> n >> r;
		cout << ar[n + 1][r + 1] << endl;
	}
	return 0;
}
