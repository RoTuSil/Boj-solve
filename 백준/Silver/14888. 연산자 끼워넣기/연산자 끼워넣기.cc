#include <iostream>
using namespace std;

int n;
int arr[11];
int o[4];
int answer;
int answerMin = INT32_MAX;
int answerMax = INT32_MIN;

void cal(int depth) {
	if (depth >= n) {
		answerMax = max(answerMax, answer);
		answerMin = min(answerMin, answer);
		return;
	}
	if (o[0] > 0) {
		o[0]--;
		answer += arr[depth];
		cal(depth + 1);
		answer -= arr[depth];
		o[0]++;
	}
	if (o[1] > 0) {
		o[1]--;
		answer -= arr[depth];
		cal(depth + 1);
		answer += arr[depth];
		o[1]++;
	}
	if (o[2] > 0) {
		o[2]--;
		answer *= arr[depth];
		cal(depth + 1);
		answer /= arr[depth];
		o[2]++;
	}
	if (o[3] > 0) {
		o[3]--;
		int temp = answer;
		answer /= arr[depth];
		cal(depth + 1);
		answer = temp;
		o[3]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> o[i];
	}
	answer = arr[0];
	cal(1);
	cout << answerMax << endl << answerMin;
}