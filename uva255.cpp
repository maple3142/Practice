#include <iostream>
using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
	Point(int n) {
		x = n % 8;
		y = n / 8;
	}
	bool operator==(Point& p) { return x == p.x && y == p.y; }
	Point operator+(Point& p) { return Point(x + p.x, y + p.y); }
	Point operator-(Point& p) { return Point(x - p.x, y - p.y); }
	int len2() { return x * x + y * y; }
	bool parallel(Point& p) {  // and same orientation
		if (p.x == 0 || x == 0)
			return p.x == x && p.y * y > 0;
		if (p.y == 0 || y == 0)
			return p.y == y && p.x * x > 0;
		return p.x / x == p.y / y;
	}
};
Point D[4] = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
int main(void) {
	ios::sync_with_stdio(false);
	int nk, nq, nm;
	while (cin >> nk >> nq >> nm) {
		Point k(nk), q(nq), m(nm);
		Point mq = m - q;
		Point kq = k - q;
		if (k == q) {
			cout << "Illegal state" << endl;
			continue;
		}
		bool not_on_same_line = q.x != m.x && q.y != m.y;
		bool moved_to_king = k == m;
		bool moved_over_king = (mq.len2() > kq.len2()) && mq.parallel(kq);
		bool no_move = q == m;
		if (not_on_same_line || moved_to_king || moved_over_king || no_move) {
			cout << "Illegal move" << endl;
			continue;
		}
		bool move_not_allowed = false;
		for (int i = 0; i < 4; i++) {
			Point x = k + D[i];
			if (m == x) {
				move_not_allowed = true;
				break;
			}
		}
		if (move_not_allowed) {
			cout << "Move not allowed" << endl;
			continue;
		}
		bool allowed_to_move = false;
		for (int i = 0; i < 4; i++) {
			Point x = k + D[i];
			if (x.x < 0 || x.x > 7 || x.y < 0 || x.y > 7)
				continue;
			if (x.x != m.x && x.y != m.y) {
				allowed_to_move = true;
				break;
			}
		}
		if (allowed_to_move) {
			cout << "Continue" << endl;
		} else {
			cout << "Stop" << endl;
		}
	}
	return 0;
}
