#include <iostream>
using namespace std;

struct Number {
	Number* next[10]{};
};

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		Number phoneBook;
		int numberCount;
		bool isValid = true;
		cin >> numberCount;
		for (int n = 0; n < numberCount; n++) {
			string phoneNumber;
			Number* ptr = &phoneBook;
			bool sameSoFar = true;
			cin >> phoneNumber;

			if (!isValid) continue;

			for (int i = 0; i < phoneNumber.length(); i++) {
				int currentDigit = phoneNumber[i] - '0';


				if (!(ptr->next[currentDigit])) {
					if (n) {
						sameSoFar = false;
					}
					ptr->next[currentDigit] = new Number;
				}

				ptr = ptr->next[currentDigit];


				if (n && sameSoFar && i < phoneNumber.length() - 1) {
					bool nvm = false;
					for (int k = 0; k < 10; k++) {
						if (ptr->next[k]) {
							nvm = true;
							break;
						}
					}
					if (!nvm) {
						isValid = false;
						break;
					}
				}

				if (i == phoneNumber.length() - 1) {
					for (int k = 0; k < 10; k++) {
						if (ptr->next[k]) {
							isValid = false;
							break;
						}
					}
				}
			}
		}
		cout << (isValid ? "YES\n" : "NO\n");
	}
}