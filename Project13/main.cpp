#include "../include/std_lib_facilities.h"
int main() {
	string from, to;
	cin >> from >> to;
	ifstream in{ from };
	ofstream out{ to };
	if (!in || !out) error("can't open file");
	vector<string> v{ istream_iterator<string>{in},istream_iterator<string>{} };
	for (auto& p : v) {
		for (auto& x : p) {
			x = tolower(x);
		}
	}
	ostream_iterator<string> oo{ out," " };
	copy(v.begin(), v.end(), oo);
	return 0;
}