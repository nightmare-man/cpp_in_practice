#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	int a = 0;
	int b = 0;
	while (cin >> a >> b) {
		cout << "the smaller is:" << ((a < b) ? a : b) << " the larger is" << ((a < b) ? b : a);
	}
	return 0;
}
int square(int x) {
	return x * x;
}