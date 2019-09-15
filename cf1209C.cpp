#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 200005;
int ar[MX];
int sorted_ar[MX];
int ans[MX];
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			ar[i] = s[i] - '0';
		}
		memcpy(sorted_ar, ar, 4 * n);
		sort(sorted_ar, sorted_ar + n);
		int i = 0, j = 0;  // i in sorted_ar, j in ar
		while (j < n && i < n) {
			if (sorted_ar[i] != ar[j]) {
				j++;
				continue;
			}
			ans[j] = 1;
			i++;
			j++;
		}
		j = 0;  // second iteration of ar
		while (j < n && i < n) {
			if (sorted_ar[i] != ar[j]) {
				j++;
				continue;
			}
			ans[j] = 2;
			i++;
			j++;
		}
		if (i < n) {
			cout << '-' << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << ans[i];
			}
			cout << endl;
		}
		memset(ar, 0, sizeof(ar));
		memset(sorted_ar, 0, sizeof(sorted_ar));
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}
