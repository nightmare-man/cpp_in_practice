#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	double a = 0;
	double b = 0;
	while (cin >> a >> b) {
		if (a-b<0.01&&b-a<0.01) cout << "numbers are almost equal\n";
		else if (a < b) cout << "the smaller is:" << a << "the larger is:" << b << "\n";
		else  cout << "the smaller is:" << b << "the larger is:" << a << "\n";
	}
	return 0;
}
int square(int x) {
	return x * x;
}