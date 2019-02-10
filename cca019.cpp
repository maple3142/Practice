#include <iostream>
using namespace std;

int sum(int n) {
	int x = 0;
	while (n) {
		x += n % 10;
		n /= 10;
	}
	return x;
}
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		while (n >= 10)
			n = sum(n);
		cout << n << endl;
	}
	return 0;
}
