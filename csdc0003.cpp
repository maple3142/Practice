#include <stdlib.h>
#include <iostream>
using namespace std;

const int MX = 100000;
struct BigInt {
	int ar[MX];
	int len;
	BigInt(int n) {
		int i = 0;
		while (n != 0) {
			ar[i] = n % 10;
			n /= 10;
			i++;
		}
		len = i;
	}
	BigInt times(BigInt x) {
		BigInt tmp(0);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < x.len; j++) {
				int r = ar[i] * x.ar[j] + tmp.ar[i + j];
				tmp.ar[i + j] = r % 10;
				tmp.ar[i + j + 1] += r / 10;
			}
		}
		for (int i = min(len + x.len, MX - 1);; i--) {
			if (tmp.ar[i] != 0) {
				tmp.len = i + 1;
				break;
			}
		}
		return tmp;
	}
	void print() {
		for (int i = len - 1; i >= 0; i--) {
			cout << ar[i];
		}
		cout << endl;
	}
};
BigInt poww(BigInt a, int n) {
	if (n == 1) {
		return a;
	}
	BigInt x = poww(a, n / 2);
	BigInt y = x.times(x);
	if (n % 2 == 1) {
		y = y.times(a);
	}
	return y;
}
int main(void) {
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		if (n == 0)
			cout << 0 << endl;
		else if (n == 1)
			cout << 1 << endl;
		else
			poww(BigInt(n), 86401).print();
	}
	return 0;
}
