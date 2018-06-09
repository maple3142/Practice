// zerojudge b966
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Line {
public:
	int start;
	int end;
	Line(int s, int e)
	    : start(s)
	    , end(e) {
	}
};
vector<Line> lines;
int main(void) {
	ios::sync_with_stdio(false);
	int n, x, y;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			lines.emplace_back(x, y);
		}
		sort(lines.begin(), lines.end(), [](const Line& a, const Line& b) {
			return a.start < b.start;
		});
		auto it = lines.begin();
		int start = it->start;
		int end = it->end;
		it++;
		int len = 0;
		for (; it != lines.end(); it++) {
			if (it->start <= end) {
				end = max(end, it->end);
			} else {
				len += (end - start);
				start = it->start;
				end = it->end;
			}
		}
		len += (end - start);
		cout << len << endl;
		lines.clear();
	}
	return 0;
}
