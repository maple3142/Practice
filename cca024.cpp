#include <iostream>
using namespace std;
typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		ll a, b, c;
		cin>>a>>b>>c;
		// bubble sort with if-statements
		if (a > b)
			swap(a, b);
		if (a > c)
			swap(a, c);
		if (b > c)
			swap(b, c);
		cout << (a + b > c ? "Yes" : "No") << endl;
	}
	return 0;
}
