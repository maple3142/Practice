#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int MOD = 2147483648;
bool mp[1000001];
int cnt = 0;
int main(void) {
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s) {
		int n = min((size_t)32, s.length());
		long long int sum = 0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				sum += pow(2, i);
				sum %= MOD;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
