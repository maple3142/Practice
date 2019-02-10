#include <iostream>
using namespace std;

int coins[] = {1000, 500, 100, 50, 10, 5, 1};
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < 7; i++) {
			int coin = coins[i];
			if (coin > n)
				continue;
			cnt += n / coin;
			n %= coin;
		}
		cout << cnt << endl;
	}
	return 0;
}
