#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef unsigned int uint;

const int MX = 2000005;
uint ar1[MX], ar2[MX];
set<uint> sums;
int main(void) {
	ios::sync_with_stdio(false);
	uint n, m, s1 = 0, s2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar1[i];
		s1 += ar1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ar2[i];
		s2 += ar2[i];
	}
	for (int i = 0; i < n; i++) {
		sums.insert(s1 - ar1[i]);
	}
	sort(ar2, ar2 + m);
	bool hasResult = false;
	for (int i = 0; i < m; i++) {
		if (sums.find(s2 - ar2[i]) != sums.end()) {
			cout << s2 - ar2[i] << endl;
			hasResult = true;
			break;
		}
	}
	if (!hasResult) {
		cout << -1 << endl;
	}
	return 0;
}
