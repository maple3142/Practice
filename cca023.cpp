#include <cstring>
#include <iostream>
using namespace std;

int ar[26];
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();
		bool adjcomply = true;
		for (int i = 0; i < len - 1; i++) {
			if (s[i] == s[i + 1]) {
				adjcomply = false;
				break;
			}
		}
		for (int i = 0; i < len; i++) {
			ar[s[i] - 'a']++;
		}
		bool amountcomply = true;
		int anycnt = 0;
		for (int i = 0; i < 26; i++) {
			if (ar[i] > 0) {
				anycnt = ar[i];
				break;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (ar[i] > 0) {
				if (anycnt != ar[i]) {
					amountcomply = false;
				}
			}
		}
		if (adjcomply && amountcomply) {
			cout << "ACCEPTED" << endl;
		} else {
			cout << "WRONG ANSWER" << endl;
		}
		memset(ar, 0, sizeof(ar));
	}
	return 0;
}
