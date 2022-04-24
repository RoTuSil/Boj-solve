#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int ropes[100000];
	int maxWeight = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ropes[i];
    
	sort(ropes, ropes + n,greater<int>());
	for (int i = 0; i < n; i++)
        maxWeight = max(maxWeight, ropes[i] * (i + 1));
	cout << maxWeight;
}