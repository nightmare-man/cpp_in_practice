#include "../include/std_lib_facilities.h"

int main() {
	int a = 1;
	int b = 1;
	while (a > 0 && b > 0) {
		int c = b;
		b = a + b;
		a = c;
		cout << a << endl;
	}
	return 0;
}
