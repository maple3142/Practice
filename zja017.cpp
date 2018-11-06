#include <iostream>
#include <stack>
using namespace std;

inline int priority(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	return 0;
}
template <typename T>
inline T pop(stack<T>& a) {
	T v = a.top();
	a.pop();
	return v;
}
int calc(int a, int b, char c) {
	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '%':
			return a % b;
		default:
			return 0;
	}
}
void fn(stack<int>& a, stack<char>& b) {
	int v1 = a.top();
	a.pop();
	int v2 = a.top();
	a.pop();
	char op = b.top();
	b.pop();
	a.push(calc(v2, v1, op));
}
int eval(string s) {
	stack<int> a;
	stack<char> b;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ')
			continue;
		else if (isdigit(s[i])) {
			int n = 0;
			while (i < len && isdigit(s[i])) {
				n = n * 10 + s[i] - '0';
				i++;
			}
			i--;
			a.push(n);
		} else if (s[i] == '(') {
			b.push(s[i]);
		} else if (s[i] == ')') {
			while (!b.empty() && b.top() != '(')
				fn(a, b);
			if (!b.empty())
				b.pop();
		} else {
			while (!b.empty() && priority(b.top()) >= priority(s[i]))
				fn(a, b);
			b.push(s[i]);
		}
	}
	while (!b.empty())
		fn(a, b);
	return a.top();
}
int main() {
	string s;
	while (getline(cin, s)) {
		cout << eval(s) << endl;
	}
}