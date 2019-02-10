#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				cout << s[j];
			}
			cout << endl;
		}
	}
	return 0;
}
