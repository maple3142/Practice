// zerojudge b964
#include <algorithm>
#include <iostream>
using namespace std;

int ar[1000];
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		sort(ar, ar + n);
		for (int i = 0; i < n; i++) {
			cout << ar[i];
			if (i + 1 != n)
				cout << ' ';
		}
		cout << endl;
		int high = -1;
		for (int i = 0; i < n; i++) {
			if (ar[i] >= 60)
				continue;
			high = max(high, ar[i]);
		}
		if (high == -1)
			cout << "best case" << endl;
		else
			cout << high << endl;
		int low = 101;
		for (int i = 0; i < n; i++) {
			if (ar[i] < 60)
				continue;
			low = min(low, ar[i]);
		}
		if (low == 101)
			cout << "worst case" << endl;
		else
			cout << low << endl;
	}
	return 0;
}
