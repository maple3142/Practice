#include <algorithm>
#include <iostream>
using namespace std;
typedef long long unsigned int ll;

const ll MX = 1000000000000000000;
ll ar[100] = {0, 1, 2};
int init() {
	int i = 3;
	while (ar[i - 1] <= MX) {
		ar[i] = ar[i - 1] + ar[i - 2] + ar[i - 3];
		i++;
	}
	return i;
}
int main() {
	int len = init();
	ll m, n;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (ar[i] >= n && ar[i] <= m) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
