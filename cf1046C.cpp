#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int points[200001];
void print_points(int n) {
	for (int i = 1; i <= n; i++) {
		cout << points[i] << ' ';
	}
	cout << endl;
}
int main(void) {
	ios::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> points[i];
	}
	multiset<int> rewards;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		rewards.insert(k);
	}
	//cout << "output" << endl;
	auto last = prev(rewards.end());
	points[d] += *last;
	rewards.erase(last);
	int val = points[d];
	sort(points + 1, points + 1 + n, greater<int>());
	//print_points(n);
	int pivot = find(points + 1, points + 1 + n, val) - (points + 1) + 1;
	//cout << "pivot" << pivot << endl;
	for (int i = 1; i < pivot; i++) {
		last = prev(rewards.end());
		points[i] += *last;
		rewards.erase(last);
	}
	for (int i = pivot + 1; i <= n; i++) {
		points[i] += *rewards.begin();
		rewards.erase(rewards.begin());
	}
	sort(points + 1, points + 1 + n, greater<int>());

	//print_points(n);

	int idx = lower_bound(points + 1, points + 1 + n, val, greater<int>()) -
	          (points + 1);
	cout << idx + 1 << endl;
	return 0;
}
