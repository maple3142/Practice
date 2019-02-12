#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> ar[26];
int main(void) {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		ar[s[i] - 'A'].push(i + 1);
	}
	int mn = 0x3f3f3f3f;
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (ar[i].size() > 0) {
			mn = min(mn, (int)ar[i].size());
			cnt++;
		}
	}
	if (cnt != m) {
		cout << 0 << endl;
		return 0;
	}
	cout << mn << endl;
	for (int i = 0; i < mn; i++) {
		for (int ch = 0; ch < m; ch++) {
			cout << ar[ch].front() << ' ';
			ar[ch].pop();
		}
		cout << endl;
	}
	return 0;
}
