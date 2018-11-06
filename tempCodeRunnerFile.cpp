#include <iostream>
#include <sstream>
using namespace std;

const int MX = 1001;
const int CMX = 1000001;
int weight[MX], demand[MX];
int dp[MX][CMX];
int main(void) {
	ios::sync_with_stdio(true);
	string s;
	getline(cin, s);
	stringstream ss;
	ss<<s;
	int n, tmp;
	while (ss >> tmp) {
		weight[n] = tmp;
		n++;
	}
	for (int i = 0; i < n; i++) {
		cin >> demand[i];
	}
	int capacity;
	cin >> capacity;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = weight[i]; j <= capacity; j++) {
			dp[i][j] = max(dp[i - 1][capacity],
			               dp[i][capacity - weight[i]] + demand[i]);
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx << endl;
}
