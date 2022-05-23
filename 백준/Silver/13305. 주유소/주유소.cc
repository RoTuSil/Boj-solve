#include <iostream>
using namespace std;

int cities;
long long oilPrice[100001]{};
long long cityLength[100001]{};

int main() {
	long long totalPrice = 0;
	cin >> cities;
	for (int i = 0; i < cities - 1; i++)
		cin >> cityLength[i];
	for (int i = 0; i < cities; i++)
		cin >> oilPrice[i];
	long long currentPrice = oilPrice[0];
	totalPrice += currentPrice * cityLength[0];
	for (int i = 1; i < cities; i++) {
		if (oilPrice[i] <= currentPrice) {
			currentPrice = oilPrice[i];
		}
		totalPrice += currentPrice * cityLength[i];
	}
	cout << totalPrice;
}