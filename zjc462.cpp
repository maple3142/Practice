#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MX = 100001;
bool ar[MX];
template <typename T>
void compress(T* ar, int n, vector<int>& v) {
	v.push_back(0);
	int curlen = 1;
	for (int i = 1; i < n; i++) {
		if (ar[i] != ar[i - 1]) {
			v.push_back(curlen);
			curlen = 0;
		}
		curlen++;
	}
	v.push_back(curlen);
}
int main(void) {
	ios::sync_with_stdio(false);
	int k, n;
	string s;
	while (cin >> k) {
		cin >> s;
		n = s.length();
		for (int i = 0; i < n; i++)
			ar[i] = (s[i] >= 'a');
		vector<int> v;
		compress(ar, n, v);
		int vsz = v.size();
		int len = 0, ans = 0;
		vector<int> v2;
		for (int i = 1; i < vsz; i++) {
			if (v[i] == k) {
				len++;
				if (v[i - 1] > k)
					len++;
			} else {
				if (v[i] > k)
					len++;
				ans = max(ans, len);
				len = 0;
			}
		}
		cout << max(ans, len) * k << endl;
	}
	return 0;
}
