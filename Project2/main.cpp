#include "../include/std_lib_facilities.h"
int main() {
	cout << "enter a float:\n";
	int a;
	cin >> a;
	cout << "a==" << a
		<< "\na+1==" << a + 1
		<< "\nhalf of a==" << a / 2
		<< "\nsqrt of a==" << sqrt(a);
	return 0;
}