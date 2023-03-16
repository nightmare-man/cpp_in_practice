#include "../include/std_lib_facilities.h"
#include "../include/std_lib_facilities.h"
const string find_min(const vector<string>& s) {
	string min{};
	if (s.size() == 0) return min;
	min = *s.begin();
	for (auto x : s) {
		if (x < min) min = x;
	}
	return min;
}
int main() {
	vector<string>p{ "sd","za","ss","aq" };
	cout << find_min(p);
	return 0;
}