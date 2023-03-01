#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<double> numbers;
	for (double tmp; cin >> tmp;) {
		numbers.push_back(tmp);
	}
	double mid = 0;
	int size = numbers.size();
	sort(numbers);

	if (size % 2 == 0) mid = (numbers[size / 2 - 1] + numbers[size / 2]) / 2;
	else mid = numbers[size / 2];
	cout << "mid is " << mid;
	return 0;
}
int square(int x) {
	return x * x;
}