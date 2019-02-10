#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << 1;
		if (i != n)
			cout << ' ';
	}
	cout << endl;
	return 0;
}
