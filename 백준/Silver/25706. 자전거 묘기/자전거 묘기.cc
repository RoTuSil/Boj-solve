#include <iostream>
using namespace std;

int ans[200001];
int ramp[200001];
int n;

int g(int p) {
	if (p >= n) return 0;

	if (ans[p] != 0) return ans[p];

	if (ramp[p] == 0)
		ans[p] = g(p + 1) + 1;
    else 
        ans[p] = g(p + ramp[p]+1) + 1;

	return ans[p];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ramp[i];
	for (int i = 0; i < n; i++)
		cout << g(i) << " ";
}