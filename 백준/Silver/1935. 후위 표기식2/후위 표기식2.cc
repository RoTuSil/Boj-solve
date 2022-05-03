#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n;
	int number[26]{};
	string eq;
	stack<double> s;
	cin >> n;
	cin >> eq;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < eq.length(); i++) {
		int t = eq[i] - 'A';
		if (t >= 0 && t < 26) {
			s.push(number[t]);
		} else {
			double a, b;
			a = s.top(); s.pop();
			b = s.top(); s.pop();
			switch (eq[i]) {
				case '+':
					s.push(b + a);
					break;
				case '-':
					s.push(b - a);
					break;
				case '*':
					s.push(b * a);
					break;
				case '/':
					s.push(b / a);
					break;
			}
		}
	}
	cout.precision(2);
	cout << fixed << s.top();
}