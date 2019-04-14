#include <cstring>
#include <iostream>
using namespace std;

const int MX = 101;
int ar1[MX], ar2[MX];
void printnum(int* ar) {
	int nonzerodg = MX;
	while (ar[nonzerodg] == 0)
		nonzerodg--;
	for (int i = nonzerodg; i >= 0; i--) {
		cout << ar[i];
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	int T, kase = 1;
	cin >> T;
	while (kase <= T) {
		cout << "Case #" << kase << ": ";
		string s;
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			ar1[len - i - 1] = s[i] - '0';
		}
		for (int i = 0; i < s.length(); i++) {
			if (ar1[i] == 4) {
				ar1[i] = 3;
				ar2[i] = 1;
			} else {
				ar2[i] = 0;
			}
		}
		printnum(ar1);
		cout << ' ';
		printnum(ar2);
		cout << endl;
		kase++;
		memset(ar1, 0, sizeof(ar1));
		memset(ar2, 0, sizeof(ar2));
	}
	return 0;
}
