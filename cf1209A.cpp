#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		s.emplace(k);
	}
	int cnt = 0;
	while (!s.empty()) {
		auto it = s.begin();
		auto it2 = s.begin();
		it2++;
		while (it2 != s.end()) {
			if (*it2 % *it == 0) {
				it2 = s.erase(it2);
			} else {
				it2++;
			}
		}
		s.erase(it);
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
