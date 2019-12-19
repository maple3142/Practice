#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Elephant {
	Elephant(int a, int b, int c) : weight(a), iq(b), idx(c) {}
	int weight, iq, idx;
};
int main(void) {
	ios::sync_with_stdio(false);
	vector<Elephant> v;
	int a, b, cnt = 0;
	while (cin >> a >> b) {
		cnt++;
		v.emplace_back(a, b, cnt);
	}
	sort(v.begin(), v.end(),
	     [](Elephant& a, Elephant& b) { return a.weight < b.weight; });
	vector<int> lis;
	vector<int> prev;
	lis.resize(cnt);
	prev.resize(cnt);
	fill(lis.begin(), lis.end(), 1);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].iq < v[j].iq && v[i].weight != v[j].weight) {
				if (lis[i] < lis[j] + 1) {
					lis[i] = lis[j] + 1;
					prev[i] = j;
				}
			}
		}
	}
	int mx = -1, mxi = 0;
	for (int i = 0; i < cnt; i++) {
		if (lis[i] > mx) {
			mx = lis[i];
			mxi = i;
		}
	}
	cout << mx << endl;

	stack<int> stk;  // to reverse output
	int c = mxi;
	while (prev[c] != c) {
		stk.push(v[c].idx);
		c = prev[c];
	}
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}
