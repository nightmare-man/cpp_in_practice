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
	double sum = 0;
	while (cin >> tmp>>sign) {
		if (sign == "m") tmp *= cm_per_m;
		else if (sign == "inch") tmp *= cm_per_inch;
		else if (sign == "ft")  tmp *= (inch_per_ft * cm_per_inch);
		else if (sign == "cm") tmp = tmp;
		else {
			cout << "undefined sign\n";
			break;
		}
		cout << "now is " << tmp << "cm" << endl;
		numbers.push_back(tmp);
		sum += tmp;
		if (tmp < min) min = tmp;
		if (tmp > max)max = tmp;
		cout << "the smallest so far:" << min << " the largest so far:" << max << endl;
	}
	cout << "the smallest:" << min << " the largest:" << max << " the sum:" << sum << " the number:" << numbers.size() << endl;
	sort(numbers);
	for (double s : numbers) {
		cout << s << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}