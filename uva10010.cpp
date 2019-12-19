#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int D[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                     {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
char ar[51][51];
int n, m;
bool findstr(int x, int y, const string& s) {
	int len = s.length();
	for (int d = 0; d < 8; d++) {
		bool matched = true;
		for (int i = 0; i < len; i++) {
			int xx = x + i * D[d][0];
			int yy = y + i * D[d][1];
			if (xx < 1 || yy < 1 || xx > n || yy > m) {
				matched = false;
				break;
			}
			if (s[i] != ar[xx][yy]) {
				matched = false;
				break;
			}
		}
		if (matched) {
			return true;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				ar[i][j] = tolower(c);
			}
		}
		int k;
		cin >> k;
		while (k--) {
			string s;
			cin >> s;
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (findstr(i, j, s)) {
						cout << i << ' ' << j << endl;
						goto outloop;
					}
				}
			}
		outloop:;
		}
		if (T > 0)
			cout << endl;
	}
	return 0;
}
