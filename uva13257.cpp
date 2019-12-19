#include <iostream>
using namespace std;

// https://acmph.blogspot.com/2017/10/link-to-problem-on-uva-online-judge.html
int nextIndex[100005][26];  // position of next character A-Z from here
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();

		// make finding position of next char faster
		for (int i = 0; i < 26; i++)
			nextIndex[len][i] = -1;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				nextIndex[i][j] = nextIndex[i + 1][j];
			}
			nextIndex[i][s[i] - 'A'] = i;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			int ia = nextIndex[0][i];  // index of first char
			if (ia == -1)
				continue;
			for (int j = 0; j < 26; j++) {
				int ib = nextIndex[ia + 1][j];  // index of second char
				if (ib == -1)
					continue;
				for (int k = 0; k < 26; k++) {
					int ic = nextIndex[ib + 1][k];  // index of thrid char
					if (ic == -1)
						continue;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
