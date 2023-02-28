#include "../include/std_lib_facilities.h"
int main() {
	constexpr double cm_per_inch = 2.54;
	double length = 1;
	char unit = 'a';
	cout << "please enter a length followed by a unit\n";
	cin >> length >> unit;
	switch (unit)
	{
	case 'i':
		cout << length << "in == " << cm_per_inch * length << "cm\n";
		break;
	case 'c':
		cout << length << " cm == " << length / cm_per_inch << "inch\n";
		break;
	default:
		break;
	}
	return 0;
}