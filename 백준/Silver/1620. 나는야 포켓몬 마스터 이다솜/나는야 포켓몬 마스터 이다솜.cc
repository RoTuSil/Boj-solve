#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int,string> pokemon;
	map<string,int> pokemonidx;
	int pnum, guess;
	cin >> pnum >> guess;
	for (int i = 0; i < pnum; i++) {
		string name;
		cin >> name;
		pokemon.insert({ i,name });
		pokemonidx.insert({ name,i });
	}
	for (int i = 0; i < guess; i++) {
		string quiz;
		cin >> quiz;
		int a = -1;
		try {
			a = stoi(quiz)-1;
			cout << pokemon[a] << "\n";
		} catch (const exception& e) {
			cout << pokemonidx[quiz]+1 << "\n";
		}
	}
}