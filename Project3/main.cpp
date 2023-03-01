#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<string> name;
	vector<int> score;
	string n = "";
	int s = 0;
	while (cin >> n >> s) {
		bool existed = false;
		for (string x: name) {
			if (x == n) {
				existed = true;
				break;
			}
		}
		if (!existed) {
			name.push_back(n);
			score.push_back(s);
		}
	}
	for (int i = 0; i < name.size(); i++) {
		cout << "name " << name[i] << " score " << score[i] << endl;
	}
	cout << "enter name ur want find:\n";
	cin >> n;
	bool existed = false;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == n) {
			existed = true;
			cout << "name " << name[i] << " score " << score[i] << endl;
			break;
		}
	}
	if (!existed) cout << "name not found\n";
	return 0;
}
int square(int x) {
	return x * x;
}