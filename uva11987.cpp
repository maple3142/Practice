#include <iostream>
using namespace std;

const int MX = 200005;
int par[MX];
int sz[MX];
int sum[MX];
inline void init(int n) {
	// By pointing i to i+n could guaranteen that action "2" won't modify any root node.
	for (int i = 1; i <= n; i++) {
		par[i] = i + n;
		par[i + n] = i + n;
		sz[i + n] = 1;
		sum[i + n] = i;
	}
}
int find_par(int p) {
	if (p == par[p])
		return p;
	return par[p] = find_par(par[p]);
}

int main(void) {
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		init(n);
		while (m--) {
			int act;
			cin >> act;
			if (act == 1) {
				int p, q;
				cin >> p >> q;
				int pa = find_par(p), qa = find_par(q);
				if (pa != qa) {
					par[pa] = qa;
					sz[qa] += sz[pa];
					sum[qa] += sum[pa];
				}
			}
			if (act == 2) {
				int p, q;
				cin >> p >> q;
				int pa = find_par(p), qa = find_par(q);
				if (pa != qa) {
					sz[qa]++;
					sum[qa] += p;
					sz[pa]--;
					sum[pa] -= p;
					par[p] = qa;
				}
			}
			if (act == 3) {
				int p;
				cin >> p;
				int pa = find_par(p);
				cout << sz[pa] << ' ' << sum[pa] << endl;
			}
			// print_par(n);
		}
	}
	return 0;
}
