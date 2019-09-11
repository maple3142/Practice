#include <algorithm>
#include <iostream>
using namespace std;

int ar[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	unsigned long long int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (ar[i] > 0) {
			sum += ar[i];
		}
	}
	if (sum == 0) {
		sort(ar, ar + n, greater<int>());
		cout << ar[0] << endl;
	} else {
		cout << sum << endl;
	}
	return 0;
}
