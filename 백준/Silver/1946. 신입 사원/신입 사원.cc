#include <iostream>
#include <algorithm>
using namespace std;

struct Score {
	int document;
	int interview;
};

bool c(const Score& a, const Score& b) {
	return a.document < b.document;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		Score score[100000];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> score[i].document >> score[i].interview;
		}
		sort(score, score + n, c);
		int rank = score[0].interview;
		int pass = 1;
		for (int i = 1; i < n; i++) {
			if (rank > score[i].interview) {
				pass++;
				rank = score[i].interview;
			}
		}
		cout << pass << "\n";
	}
}