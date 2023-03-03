#include "../include/std_lib_facilities.h"
vector<string> ccin = { "thousand","hundred","ten","one" };
int main() {
	char ch;
	string num = "";
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> ch;
		if (!(ch >= '0' && ch <= '9')) break;
		num += ch;
	}
	cout << num << " is ";
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << " " << ccin[i + 4 - num.size()]<<" ";
	}
	return 0;
}