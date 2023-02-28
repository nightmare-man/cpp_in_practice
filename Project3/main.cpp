#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	constexpr  double  cm_per_inch =2.54;
	constexpr double cm_per_m = 100;
	constexpr double inch_per_ft = 12;
	vector<double> numbers;
	double max=-32767;
	double min=32767;
	double tmp = 0;
	string sign = "";
	while (cin >> tmp>>sign) {
		if (sign == "m") tmp *= cm_per_m;
		else if (sign == "inch") tmp *= cm_per_inch;
		else if (sign == "ft")  tmp *= (inch_per_ft * cm_per_inch);
		else {
			cout << "undefined sign\n";
			break;
		}
		cout << "now is " << tmp << "cm" << endl;
		numbers.push_back(tmp);
		if (tmp < min) min = tmp;
		if (tmp > max)max = tmp;
		cout << "the smallest so far:" << min << " the largest so far:" << max << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}