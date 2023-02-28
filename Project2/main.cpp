#include "../include/std_lib_facilities.h"
int main() {
	double mile1 = 0;
	double mile2 = 0;
	cout << "enter mile:\n";
	cin >> mile1;
	mile2 = mile1 * 1.609;
	cout << "transfer to " << mile2 << "mile\n";
	return 0;
}