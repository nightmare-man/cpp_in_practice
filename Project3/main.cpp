#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	double max=-32767;
	double min=32767;
	double tmp = 0;
	while (cin >> tmp) {
		if (tmp < min) min = tmp;
		if (tmp > max)max = tmp;
		cout << "the smallest so far:" << min << " the largest so far:" << max << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}