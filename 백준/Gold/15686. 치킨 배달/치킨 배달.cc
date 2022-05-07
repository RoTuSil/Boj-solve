#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
};

vector<Point> houses;
vector<Point> chicken;
int map[50][50]{};
int mapSize;
int minimumChicken;
int minCityChickenDistance = 214748364;
bool chickenIncluded[13];

int getHouseChickenDistance(Point from,Point to){
	return abs(from.y - to.y) + abs(from.x - to.x);
}

int getMinHouseChickenDistanceOf(Point house) {
	int minDistance = 214748364;
	for (int i = 0; i < chicken.size(); i++) {
		if(chickenIncluded[i])
			minDistance = min(minDistance, getHouseChickenDistance(house, chicken[i]));
	}
	return minDistance;
}

int getCityChickenDistance() {
	int cityDistance = 0;
	for (int i = 0; i < houses.size(); i++) {
		cityDistance += getMinHouseChickenDistanceOf(houses[i]);
	}
	return cityDistance;
}

void getMinCityChickenDistance(int depth, int startIndex) {
	if (depth == minimumChicken) {
		minCityChickenDistance = min(minCityChickenDistance, getCityChickenDistance());
		return;
	}
	for (int i = startIndex; i < chicken.size(); i++) {
		chickenIncluded[i] = true;
		getMinCityChickenDistance(depth + 1, i + 1);
		chickenIncluded[i] = false;
	}
}

int main() {
	cin >> mapSize >> minimumChicken;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) houses.push_back({ j,i });
			if (map[i][j] == 2) chicken.push_back({ j,i });
		}
	}
	getMinCityChickenDistance(0, 0);
	cout << minCityChickenDistance;
}