#include <iostream>
using namespace std;

struct Card {
	char suit;
	int number;
	Card(string s) {
		suit = s[0];
		number = s[1] - '0';
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		Card main(s);
		bool ok = false;
		for (int i = 0; i < 5; i++) {
			cin >> s;
			Card card(s);
			if (card.number == main.number || card.suit == main.suit) {
				ok = true;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}
