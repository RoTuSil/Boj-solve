#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		map<string, int> wear;
		vector<string> wearPart;
		int wearCount;
		cin >> wearCount;
		for (int i = 0; i < wearCount; i++) {
			string name, part;
			cin >> name >> part;
			if (wear[part] == 0) {
				wearPart.push_back(part);
			}
			wear[part]++;
		}
		int mult = 1;
		for (string s : wearPart) {
			mult *= wear[s] + 1;
		}
		cout << --mult << "\n";
	}
}
