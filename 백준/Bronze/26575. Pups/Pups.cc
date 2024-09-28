#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double a, b, c;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		cout << fixed << setprecision(2) << "$" << a * b * c << endl;
	}
}