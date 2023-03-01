#include "../include/std_lib_facilities.h"
/// <summary>
/// c>=-273.15
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
double ctok(double c) {
	constexpr double min = 273.15;
	if (c < -min) error("wrong argument in ctok()\n");
	double k = c + min;
	return k;
}
int main() {
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';
	return 0;
}
