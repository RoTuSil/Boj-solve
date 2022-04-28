#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Jewel {
	int weight;
	int value;
};

bool c(const Jewel& a, const Jewel& b) {
	if (a.weight == b.weight)
		return a.value < b.value;

	return a.weight < b.weight;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<Jewel> jewel;
	vector<int> bag;
	priority_queue<int> price;
	int jewelCount, bagCount;
	long long totalPrice = 0;

	cin >> jewelCount >> bagCount;
	for (int i = 0; i < jewelCount; i++) {
		int a, b;
		cin >> a >> b;
		jewel.push_back({ a,b });
	}
	for (int i = 0; i < bagCount; i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}
	sort(jewel.begin(), jewel.end(), c);
	sort(bag.begin(), bag.end());
	for (int i = 0,j = 0; i < bagCount; i++) {
		while (true) {
			if (j >= jewelCount) break;
			if (jewel[j].weight > bag[i]) break;
			price.push(jewel[j++].value);
		}
		if (!price.empty()) {
			totalPrice += price.top();
			price.pop();
		}
	}
	cout << totalPrice;
}