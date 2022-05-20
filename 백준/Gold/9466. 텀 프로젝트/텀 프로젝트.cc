#include <iostream>
using namespace std;

int teamedStudentCount;
int cycleStart = -1;
int selected[100001];
bool* visited;
bool isVisiting[100001];

void checkCycle(int index) {
	if (visited[index]) return;
	if (isVisiting[selected[index]]) {
		cycleStart = selected[index];
		visited[index] = true;
		teamedStudentCount++;
		return;
	}

	isVisiting[selected[index]] = true;
	checkCycle(selected[index]);
	isVisiting[selected[index]] = false;

	visited[index] = true;
	if (cycleStart == -1) {
		return;
	}
	teamedStudentCount++;
	if (index == cycleStart) {
		cycleStart = -1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int student;
		cin >> student;
		visited = new bool[student + 1]{};
		for (int i = 1; i <= student; i++) {
			cin >> selected[i];
			if (selected[i] == i) {
				teamedStudentCount++;
				visited[i] = true;
			}
		}
		for (int i = 1; i <= student; i++) {
			if (!visited[i]) {
				checkCycle(i);
			}
		}
		cout << student -  teamedStudentCount << "\n";

		delete[] visited;
		teamedStudentCount = 0;
	}
}