#include "../include/std_lib_facilities.h"

int main() {
	try {
		int res = 7; vector<int> v(10); v[5] = res; cout << "success\n";
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
