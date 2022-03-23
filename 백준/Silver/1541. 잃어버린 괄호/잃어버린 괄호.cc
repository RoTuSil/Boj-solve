#include <iostream>
using namespace std;


int main() {
	int arr[30] = {};
	int temp = 0, idx = 0;
	string str;
	bool isNegative = false;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-') {
			if (isNegative)
				temp = -temp;
			arr[idx++] = temp;
			temp = 0;
			isNegative = true;
			continue;
		}
		if (str[i] == '+') {
			if (isNegative)
				temp = -temp;
			arr[idx++] = temp;
			temp = 0;
			isNegative = false;
			continue;
		}
		temp *= 10;
		temp += str[i] - '0';
		if (i == str.length() - 1) {
			if (isNegative)
				temp = -temp;
			arr[idx++] = temp;
		}
	}
	int sum = 0;
	int sumTemp = 0;
	for (int i = 0; i < idx;) {
		if (arr[i] < 0) {
			
			sumTemp -= arr[i];
			i++;
			if(arr[i]>=0)
				while (arr[i] >= 0 && i < idx) {
					sumTemp += arr[i];
					i++;
				}
			sum -= sumTemp;
			sumTemp = 0;
		} else {
			sum += arr[i++];
		}
	}
	cout << sum;
}