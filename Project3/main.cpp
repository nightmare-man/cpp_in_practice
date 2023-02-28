#include "../include/std_lib_facilities.h"
int main() {
	constexpr double pi = 3.14159;
	double span = 0;
	cin >> span;
	cout << "span "<<span <<" cicle's length is" << 2 * pi * span;
	pi = 100;
	return 0;
}