#include <iostream>
using namespace std;

bool mp[1000001];
int cnt = 0;
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (!mp[k]) {
			mp[k] = true;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
