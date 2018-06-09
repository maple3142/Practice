// zerojudeg b967
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

const int MX = 100001;
int in[MX];
vector<int> children[MX];
int mxdep = 0;
int dfs(int now) {
	int sz = children[now].size();
	if (sz == 0)
		return 1;
	else if (sz == 1)
		return dfs(children[now][0]) + 1;
	else {
		int mx1 = 0, mx2 = 0;
		for (int x : children[now]) {
			int d = dfs(x);
			if (d > mx1) {
				mx2 = mx1;
				mx1 = d;
			} else if (d > mx2) {
				mx2 = d;
			}
		}
		mxdep = max(mxdep, mx1 + mx2);
		return mx1 + 1;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	int n, a, b;
	while (cin >> n) {
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			children[a].push_back(b);
			in[b]++;
		}
		int root;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				root = i;
				break;
			}
		}
		int rdep = dfs(root);
		cout << max(rdep - 1, mxdep) << endl;
		memset(in, 0, sizeof(in));
		memset(children, 0, sizeof(children));
		mxdep = 0;
	}
	return 0;
}
