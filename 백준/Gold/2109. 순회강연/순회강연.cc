#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct p {
	int price;
	int day;
};

bool c (const p& a, const p& b) {
	return a.day > b.day;
}

int main() {
	priority_queue<int> pq;
	vector<p> arr;
	int suggested;
	int totalPrice = 0;
	int lectureDay;

	cin >> suggested;
	if (suggested == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < suggested; i++) {
		int price, day;
		cin >> price >> day;
		arr.push_back({ price,day });
	}
    
	sort(arr.begin(), arr.end(), c);
	lectureDay = arr[0].day;
    
	for (int i = lectureDay, j = 0; i > 0; i--) {
		while (true) {
			if (j >= suggested) break;
			if (arr[j].day < i) break;
			pq.push(arr[j++].price);
		}
		if (!pq.empty()) {
			totalPrice += pq.top();
			pq.pop();
		}
	}
	cout << totalPrice;
}