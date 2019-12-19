#include <algorithm>
#include <iostream>
using namespace std;

/*
 * 1. The left id of node N is N*2
 * 2. The right id of node N is N*2+1
 * 3. If I is odd, it will fall to left, and be the (I+1)/2 ball falling into the left.
 * 4. If I is even, it will fall to right, and be the I/2 ball falling into the right.
*/
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int D, I;
		cin >> D >> I;
		int ans = 1;
		for (int i = 1; i < D; i++) {  // D-1 times
			if (I % 2 == 1) {
				ans = ans * 2;
				I = (I + 1) / 2;
			} else {
				ans = ans * 2 + 1;
				I = I / 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
