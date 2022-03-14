#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string number="";
	int sum = 0;
	cin >> number;
	sort(number.begin(), number.end(),greater<char>());
	for (int i = 0; i < number.length(); i++) {
		sum += (number[i] - '0');
	}
	if (sum % 3 != 0 || number.back() != '0') {
		cout << -1;
		return 0;
	} 
	cout << number;
}