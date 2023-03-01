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
double ktoc(double k) {
	constexpr double min = 273.15;
	if (k < 0) error("wrong argument in ctok()\n");
	double c = k- min;
	return c;
}
int main() {
	double k = 0;
	cin >> k;
	double c = 0;
	try {
		c = ktoc(k);
	}
	catch (exception& e) {
		cout << "exception: " << e.what() << endl;
	}
	
	cout << c << '\n';
	return 0;
}
