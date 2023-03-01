#include "../include/std_lib_facilities.h"
class Bad_area {};
double do_something();
int main() {
	try {
		//int x1 = narrow_cast<int>(2.9);
		int x2 = narrow_cast<int>(2.0);
	}
	catch (exception& e) {
		cerr << "runtime error:" << e.what() << endl;
	}
	catch (...) {
		cerr << "unknow exception!\n";
	}
	
	return 0;
}
double do_something() {
	double a = 0;
	cin >> a;
	if (!cin) error("couldn't read a double in main function\n");
	return a;
}