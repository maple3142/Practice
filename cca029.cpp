#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int XX[] = {1, 0, -1, 0};
const int YY[] = {0, 1, 0, -1};
const int MX = 1005;
unsigned int ar[MX][MX];
bool vis[MX][MX];
int main(void) {
	ios::sync_with_stdio(false);
	int n, k, r;
	cin >> n >> k >> r;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = true;
	}
	memset(ar, 0x3f, sizeof(ar));
	ar[1][1] = 0;
	vis[1][1] = true;
	queue<pii> q;
	q.emplace(1, 1);
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		ar[x][y] = min(ar[x][y],
		               min(ar[x - 1][y],
		                   min(ar[x][y - 1], min(ar[x + 1][y], ar[x][y + 1]))) +
		                   1);
		for (int i = 0; i < 4; i++) {
			int nx = x + XX[i], ny = y + YY[i];
			if (vis[nx][ny] || nx == 0 || ny == 0 || nx > n || ny > n)
				continue;
			q.emplace(nx, ny);
			vis[nx][ny] = true;
		}
	}
	for (int i = 0; i < r; i++) {
		int c, d;
		cin >> c >> d;
		int ans = ar[c][d];
		cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
	}
	return 0;
}
