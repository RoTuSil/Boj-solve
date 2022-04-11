#include <iostream>
using namespace std;

struct Gear {
	char gearSides[9];
	int gearTop = 0;

	void rotate(int dir) {
		gearTop -= dir;
		if (gearTop == -1) gearTop = 7;
		else if (gearTop == 8) gearTop = 0;
	}

	bool isSameSideWith(const Gear& g) {
		int leftgear = (gearTop + 2) % 8;
		int rightgear = (g.gearTop + 6) % 8;
		return (gearSides[leftgear] == g.gearSides[rightgear]);
	}

	int getGearTop() {
		return (gearSides[gearTop] == '0' ? 0 : 1);
	}
};

int main() {
	Gear gears[4];
	bool sameSide_1_2;
	bool sameSide_2_3;
	bool sameSide_3_4;
	int rotateCount;
	for (int i = 0; i < 4; i++) {
		cin >> gears[i].gearSides;
	}

	cin >> rotateCount;
	for (int i = 0; i < rotateCount; i++) {

		sameSide_1_2 = gears[0].isSameSideWith(gears[1]);
		sameSide_2_3 = gears[1].isSameSideWith(gears[2]);
		sameSide_3_4 = gears[2].isSameSideWith(gears[3]);
		int gearToRotate, rotateDir;
		cin >> gearToRotate >> rotateDir;
		switch (gearToRotate) {
			case 1:
				gears[0].rotate(rotateDir);
				if (!sameSide_1_2) {
					gears[1].rotate(-rotateDir);
					if (!sameSide_2_3) {
						gears[2].rotate(rotateDir);
						if (!sameSide_3_4) {
							gears[3].rotate(-rotateDir);
						}
					}
				}
				break;
			case 2:
				gears[1].rotate(rotateDir);
				if (!sameSide_1_2)
					gears[0].rotate(-rotateDir);
				if (!sameSide_2_3) {
					gears[2].rotate(-rotateDir);
					if (!sameSide_3_4) {
						gears[3].rotate(rotateDir);
					}
				}
				break;
			case 3:
				gears[2].rotate(rotateDir);
				if (!sameSide_3_4)
					gears[3].rotate(-rotateDir);
				if (!sameSide_2_3) {
					gears[1].rotate(-rotateDir);
					if (!sameSide_1_2) {
						gears[0].rotate(rotateDir);
					}
				}
				break;
			case 4:
				gears[3].rotate(rotateDir);
				if (!sameSide_3_4) {
					gears[2].rotate(-rotateDir);
					if (!sameSide_2_3) {
						gears[1].rotate(rotateDir);
						if (!sameSide_1_2) {
							gears[0].rotate(-rotateDir);
						}
					}
				}
				break;
		}
	}
	int score=0;
	if (gears[0].getGearTop()) score += 1;
	if (gears[1].getGearTop()) score += 2;
	if (gears[2].getGearTop()) score += 4;
	if (gears[3].getGearTop()) score += 8;
	cout << score;
}
