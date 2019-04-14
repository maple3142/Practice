#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int T, kase = 1;
	cin >> T;
	while (kase <= T) {
		cout << "Case #" << kase << ": ";
		int n;
		cin >> n;
		string s;
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[i] == 'S')
				cout << 'E';
			else
				cout << 'S';
		}
		cout << endl;
		kase++;
	}
	return 0;
}
