#include <iostream>
using namespace std;

struct TreeNode {
	int value = -1;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	void insert(int n) {
		if (value == -1) {
			value = n;
			return;
		}
		if (n < value) {
			if (!left) {
				left = new TreeNode;
				left->value = n;
			} else {
				left->insert(n);
				return;
			}
		} else if (n > value) {
			if (!right) {
				right = new TreeNode;
				right->value = n;
			} else {
				right->insert(n);
				return;
			}
		}
	}

	void print() {
		if(left) left->print();
		if(right) right->print();
		cout << value << "\n";
	}
};

int main() {
	TreeNode tree;
	int n;
	while (true) {
		cin >> n;
		if (cin.eof() == true) break;
		tree.insert(n);
	}
	tree.print();
}