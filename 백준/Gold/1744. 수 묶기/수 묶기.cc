#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> positive;
	vector<int> negative;
	int zeroCount = 0;
	int n, answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (number == 0) zeroCount++;
		else if (number > 0) positive.push_back(number);
		else if (number < 0) negative.push_back(number);
	}
	if(!positive.empty())
		sort(positive.begin(), positive.end());
	if(!negative.empty())
		sort(negative.begin(), negative.end(), greater<int>());
	while (true) {
		if (positive.empty() && negative.empty()) break;
		if (!positive.empty()) {
			if (positive.size() == 1) {
				answer += positive.back();
				positive.pop_back();
			} else if (positive.size() > 1) {
				int a, b;
				a = positive.back();
				positive.pop_back();
				b = positive.back();
				positive.pop_back();
				if (a == 1 || b == 1) {
					answer += (a + b);
				} else {
					answer += (a * b);
				}
			}
		}
		if (!negative.empty()) {
			if (negative.size() == 1) {
				if (zeroCount > 0) {
					negative.pop_back();
					continue;
				} else {
					answer += negative.back();
					negative.pop_back();
				}
			} else if (negative.size() > 1) {
				int a, b;
				a = negative.back();
				negative.pop_back();
				b = negative.back();
				negative.pop_back();
				answer += (a * b);
			}
		}
	}
	cout << answer;
}