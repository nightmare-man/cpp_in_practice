#include "../include/std_lib_facilities.h"
class Bad_area {};
double do_something();
int main() {
	try {
		do_something();
	}
	catch (exception& e) {
		cerr << "runtime error:" << e.what() << endl;
	}
	
	return 0;
}
double do_something() {
	double a = 0;
	cin >> a;
	if (!cin) error("couldn't read a double in main function\n");
	return a;
}