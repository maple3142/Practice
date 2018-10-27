#include <iostream>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int qpow(int a, int b) {
	if (b == 1)
		return a;
	int x = qpow(a, b / 2);
	return b % 2 == 0 ? x * x : x * x * a;
}
int n, pn;
string s;
pii dfs(int cur, int deep = 0) {
	int cnt = 0;
	int i = cur;
	for (int j = 0; j < 4; j++) {
		char c = s[i] - '0';
		if (c == 2) {
			pii x = dfs(i + 1, deep + 1);
			cnt += x.first;
			i += x.second;
		} else if (c == 1) {
			cnt += pn / qpow(4, deep);
		}
		i++;
	}
	return pii(cnt, i - cur);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	pn = qpow(2, 2 * n);
	cout << dfs(0).first << endl;
}
