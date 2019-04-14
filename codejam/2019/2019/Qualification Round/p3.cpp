#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int ar[101];
int p[26];
int main(void) {
	ios::sync_with_stdio(false);
	int T, kase = 1;
	cin >> T;
	while (kase <= T) {
		cout << "Case #" << kase << ": ";
		int n, l;
		cin >> n >> l;
		for (int i = 0; i < l; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < l; i++) {
			p[i + 1] = __gcd(ar[i], ar[i + 1]);
		}
		p[0] = ar[0] / p[1];
		p[l] = ar[l - 1] / p[l - 1];
		// for (int i = 0; i <= l; i++) {
		// 	cout << "p[" << i << "]=" << p[i] << endl;
		// }
		for (int i = 0; i < l; i++) {
			if (p[i] * p[i + 1] != ar[i] && p[i + 1] != 0) {
				p[i] = ar[i] / p[i + 1];
			}
		}
		for (int i = l - 1; i >= 0; i--) {
			if (p[i] * p[i + 1] != ar[i] && p[i + 1] != 0) {
				p[i] = ar[i] / p[i + 1];
			}
		}
		// for (int i = 0; i <= l; i++) {
		// 	cout << "p[" << i << "]=" << p[i] << endl;
		// }
		vector<int> v;
		v.assign(p, p + l + 1);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		unordered_map<int, char> mp;
		for (int i = 0; i < v.size(); i++) {
			mp[v[i]] = i + 'A';
			// cout<<v[i]<<"->"<<char(i+'A')<<endl;
		}
		char res[105];
		for (int i = 0; i <= l; i++) {
			res[i] = mp[p[i]];
		}
		for (int i = 0; i <= l; i++) {
			cout << res[i];
		}
		cout << endl;
		kase++;
		mp.clear();
	}
	return 0;
}
