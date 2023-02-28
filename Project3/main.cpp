#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<string> week{ "w1","w2" };
	for (int i = 0; i < week.size(); i++) {
		cout << week[i] << endl;
	}
}
int square(int x) {
	return x * x;
}