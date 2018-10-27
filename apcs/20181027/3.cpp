#include <iostream>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

/*
 * Q:
 * 輸入整數 n 與字串 s，n 代表以 2^n 為邊長的正方形，s 是正方形的排列
 * 如 s = 2200101020011 代表: (2 代表分隔為 4 塊，接著的 4 個數字依序代表 4 個區塊的模樣)
 * 0011
 * 0111
 * 0000
 * 0011
*/

int qpow(int a, int b) {
	/*
	 * 快速冪
	 * if(n % 2 == 0) a^b = a^(b/2) * a^(b/2)
	 * else a^b = a^(b/2) * a^(b/2) * a
	*/
	if (b == 0)
		return 1;
	int x = qpow(a, b / 2);
	return b % 2 == 0 ? x * x : x * x * a;
}
int n;
string s;
pii dfs(int start, int deep = 0) {
	int cnt = 0;
	int cursor = start;
	for (int j = 0; j < 4; j++) {
		int c = s[cursor] - '0';
		if (deep == 0 & j > 0) // 第 0 層第一個數字如果不是 2 根本不會有後面的出現
			break;
		if (c == 2) {
			// 如果是 2，則把後面的交給下一層來判斷
			pii x = dfs(cursor + 1, deep + 1);
			// 然後加上傳回來的 cnt 和 curson 移動的距離
			cnt += x.first;
			cursor += x.second;
		} else if (c == 1) {
			// 是 1 就加上本層每格的格子數量 (2^2n) / (4^m) = 4^(n - m)
			cnt += qpow(4, n - deep);
		}
		cursor++;
	}
	return pii(cnt, cursor - start); // 回傳 cnt 與 cursor 移動的距離
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	cout << dfs(0).first << endl;
}
