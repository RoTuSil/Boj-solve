#include <iostream>
#include <vector>
using namespace std;

int main() {
	string originalAddress;
	vector<string> splitAddress;
	string result[8]{};
	string temp = "";
	cin >> originalAddress;
	for (int i = 0; i < originalAddress.length(); i++) {
		if (i != originalAddress.length() - 1) {
			if (originalAddress[i] == ':' && originalAddress[i + 1] == ':') {
				if (temp != "") {
					splitAddress.push_back(temp);
					temp = "";
				}
				splitAddress.push_back("::");
				i++;
				continue;
			}
		}
		if (originalAddress[i] == ':') {
			splitAddress.push_back(temp);
			temp = "";
		} else {
			temp.push_back(originalAddress[i]);
		}
	}
	if (temp != "") splitAddress.push_back(temp);
	for (int i = 0; i < splitAddress.size();i++) {
		if (splitAddress[i] == "::") {
			for (int j = 0; j <= 8 - splitAddress.size(); j++) {
				cout << "0000";
				if (i + j < 7) cout << ':';
			}
		} else {
			if (splitAddress[i].size() < 4) {
				for (int j = 0; j < 4 - splitAddress[i].size();j++) {
					cout << "0";
				}
			}
			cout << splitAddress[i];
			if (i < splitAddress.size() - 1) cout << ':';
		}
	}
}