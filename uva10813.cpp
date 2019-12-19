#include <memory.h>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
bool check(T ar) {
	for (int i = 1; i <= 5; i++) {
		bool all_true = true;
		for (int j = 1; j <= 5; j++) {
			if (!ar[i][j]) {
				all_true = false;
				break;
			}
		}
		if (all_true) {
			return true;
		}
	}
	for (int i = 1; i <= 5; i++) {
		bool all_true = true;
		for (int j = 1; j <= 5; j++) {
			if (!ar[j][i]) {
				all_true = false;
				break;
			}
		}
		if (all_true) {
			return true;
		}
	}
	{
		bool all_true = true;
		for (int i = 1; i <= 5; i++) {
			if (!ar[i][i]) {
				all_true = false;
				break;
			}
		}
		if (all_true) {
			return true;
		}
	}
	{
		bool all_true = true;
		for (int i = 1; i <= 5; i++) {
			if (!ar[6 - i][i]) {
				all_true = false;
				break;
			}
		}
		if (all_true) {
			return true;
		}
	}
	return false;
}
pair<int, int> cards[76];
bool marked[6][6];
int tmp[76];
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				marked[i][j] = false;
				if (i == 3 && j == 3)
					continue;
				int n;
				cin >> n;
				cards[n] = {i, j};
			}
		}
		marked[3][3] = true;
		for (int i = 1; i <= 75; i++) {
			cin >> tmp[i];
		}
		for (int i = 1; i <= 75; i++) {
			int n = tmp[i];
			auto p = cards[n];
			marked[p.first][p.second] = true;
			if (check(marked)) {
				cout << "BINGO after " << i << " numbers announced" << endl;
				break;
			}
		}
		memset(cards, 0, sizeof(cards));
	}
	return 0;
}
