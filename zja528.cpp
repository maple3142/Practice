#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MX = 1005;
int leadingZero(string s) {
	int cnt = 0, len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] != '0')
			return cnt;
		cnt++;
	}
	return cnt;
}
struct Num {
	bool neg = false;
	int len;
	int ar[MX];
	string str;
	Num() {}
	Num(string s) {
		str = s;
		if (s[0] == '-') {
			neg = true;
			s = s.substr(1);
		}
		s = s.substr(leadingZero(s));
		len = s.length();
		for (int i = 0; i < len; i++) {
			ar[i] = s[i] - '0';
		}
	}
	bool less(Num& b) {
		if (!b.neg && neg)
			return true;
		else if (b.neg && !neg)
			return false;
		else if (neg && b.neg) {
			this->neg = false;
			b.neg = false;
			bool r = !(this->less(b));
			this->neg = true;
			b.neg = true;
			return r;
		} else if (len < b.len)
			return true;
		else if (len > b.len)
			return false;
		for (int i = len - 1; i >= 0; i--) {
			if (b.ar[i] > ar[i])
				return true;
		}
		return false;
	}
};
Num ar[1001];
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			ar[i] = s;
		}
		std::sort(ar, ar + n, [](Num& a, Num& b) { return a.less(b); });
		for (int i = 0; i < n; i++) {
			cout << ar[i].str << endl;
		}
	}
}
