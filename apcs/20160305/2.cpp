// zerojudge b965
#include <iostream>
#include <stack>
using namespace std;

int ar[100][100];
int tmp[100][100];
int main(void) {
	ios::sync_with_stdio(false);
	int r, c, m, a;
	while (cin >> r >> c >> m) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> ar[i][j];
			}
		}
		stack<int> stk;
		while (m--) {
			cin >> a;
			stk.push(a);
		}
		while (!stk.empty()) {
			a = stk.top();
			stk.pop();
			if (a == 0) {
				for (int i = 1; i <= r; i++) {
					for (int j = 1; j <= c; j++) {
						tmp[c - j + 1][i] = ar[i][j];
					}
				}
				swap(r, c);
				for (int i = 1; i <= r; i++) {
					for (int j = 1; j <= c; j++) {
						ar[i][j] = tmp[i][j];
					}
				}
			} else {
				for (int i = 1; i <= r; i++) {
					for (int j = 1; j <= c; j++) {
						tmp[r - i + 1][j] = ar[i][j];
					}
				}
				for (int i = 1; i <= r; i++) {
					for (int j = 1; j <= c; j++) {
						ar[i][j] = tmp[i][j];
					}
				}
			}
		}
		cout << r << ' ' << c << endl;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << ar[i][j];
				if (j < c)
					cout << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
