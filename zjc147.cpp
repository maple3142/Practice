#include <iostream>
#include <sstream>
using namespace std;

const int MX = 1001;
const int CMX = 1000001;
int weight[MX], demand[MX];
int dp[CMX] = {};
int main(void) {
	ios::sync_with_stdio(true);
	string s;
	getline(cin, s);
	stringstream ss;
	ss << s;
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
	for (int i = 1; i < n; i++) {
		for (int j = capacity; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + demand[i]);
		}
	}
	cout << dp[capacity] << endl;
}
