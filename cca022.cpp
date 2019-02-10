#include <cstring>
#include <iostream>
using namespace std;

const int MX = 1000000;
int coins[] = {1000, 500, 100, 50, 35, 5, 1};
int dp[MX];
int main(void) {
	ios::sync_with_stdio(false);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i < MX; i++) {
		for (int j = 6; j >= 0; j--) {
			if (i - coins[j] < 0)
				break;
			dp[i] = min(dp[i - coins[j]], dp[i]);
		}
		dp[i]++;
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
