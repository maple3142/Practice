#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

template <int N>
struct prime_table {
	/*constexpr*/ prime_table() : isprime(), primes() {
		for (int i = 2; i < N; i++)
			isprime[i] = true;
		for (int i = 2; i <= sqrt(N); i++)
			if (isprime[i])
				for (int j = i + i; j < N; j += i)
					isprime[j] = false;
		for (int i = 2; i <= N; i++)
			if (isprime[i])
				primes.push_back(i);
	}
	bool isprime[N];
	vector<int> primes;
};
const int MX = 20000000;
auto table = prime_table<MX>();
int main(int argc, char** argv) {
	// 4c-3=(2a-1)(2b-1)
	ll c;
	while (cin >> c) {
		if (c == 0)
			break;
		ll n = 4 * c - 3;  // odd
		int ans = 1;
		for (int i = 0; i < table.primes.size() && table.primes[i] <= sqrt(n);
		     i++) {
			int cnt = 0;
			while (n % table.primes[i] == 0) {
				cnt++;
				n /= table.primes[i];
			}
			ans *= (cnt + 1);
		}
		if (n != 1) {
			ans *= 2;
		}
		cout << c << ' ' << ans << endl;
	}
}
