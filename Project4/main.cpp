#include "../include/std_lib_facilities.h"

int main() {
	try {
		int x = 4; double d = 5.0/ (x - 2); if (d == 2+ 0.5) cout << "success\n";
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "error:" << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "oops:unknow exception!\n";
		keep_window_open();
		return 2;
	}
	return 0;
}
