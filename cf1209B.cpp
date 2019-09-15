#include <algorithm>
#include <iostream>
using namespace std;

bool light[100];
int start[100];
int per[100];
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		light[i] = s[i] == '1';
		if (light[i]) {
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> per[i] >> start[i];
	}
	for (int t = 1; t <= 100000; t++) {
		int lcnt = 0;
		for (int i = 0; i < n; i++) {
			if ((t - start[i]) >= 0 &&
			    (t - start[i]) % per[i] == 0) {  // time to toggle
				light[i] = !light[i];
			}
			if (light[i]) {
				lcnt++;
			}
		}
		cnt = max(lcnt, cnt);
	}
	cout << cnt << endl;
	return 0;
}
