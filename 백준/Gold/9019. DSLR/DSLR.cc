#include <iostream>
#include <queue>
using namespace std;

int D(int n) {
	return n * 2 % 10000;
}

int S(int n) {
	int newN = n - 1;
	return (newN >= 0 ? newN : 9999);
}

int L(int n) {
	int digit[4]{};
	digit[0] = n / 1000;
	digit[1] = (n % 1000) / 100;
	digit[2] = (n % 100) / 10;
	digit[3] = (n % 10);
	int newN = digit[1] * 1000 + digit[2] * 100 + digit[3] * 10 + digit[0];
	return newN;
}

int R(int n) {
	int digit[4]{};
	digit[0] = n / 1000;
	digit[1] = (n % 1000) / 100;
	digit[2] = (n % 100) / 10;
	digit[3] = (n % 10);
	int newN = digit[3] * 1000 + digit[0] * 100 + digit[1] * 10 + digit[2];
	return newN;
}

struct element {
	int value;
	string path;
};

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		bool visited[10000]{};
		int from, end;
		queue<element> q;
		cin >> from >> end;

		visited[from] = true;
		q.push({ from, "" });
		while (!q.empty()) {
			element now = q.front();
			q.pop();

			if (now.value == end) {
				cout << now.path + "\n";
			}
			int n = now.value;
			int dn = D(n), sn = S(n), ln = L(n), rn = R(n);
			if (!visited[dn]) {
				visited[dn] = true;
				q.push({ dn, now.path + "D" });
			}
			if (!visited[sn]) {
				visited[sn] = true;
				q.push({ sn, now.path + "S" });
			}
			if (!visited[ln]) {
				visited[ln] = true;
				q.push({ ln, now.path + "L" });
			}
			if (!visited[rn]) {
				visited[rn] = true;
				q.push({ rn, now.path + "R" });
			}
		}
 	}
}