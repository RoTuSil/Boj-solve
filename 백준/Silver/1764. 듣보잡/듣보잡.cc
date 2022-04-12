#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> nosee;
	vector<string> noHearNoSee;
	string name;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		nosee.insert({ name, i });
	}
	for (int j = 0; j < m; j++) {
		cin >> name;
		if (nosee.find(name) != nosee.end()) {
			noHearNoSee.push_back(name);
		}
	}
	sort(noHearNoSee.begin(),noHearNoSee.end());
	cout << noHearNoSee.size() << "\n";
	for (int i = 0; i < noHearNoSee.size(); i++) {
		cout << noHearNoSee[i] << "\n";
	}
}