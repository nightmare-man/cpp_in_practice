#include "../include/std_lib_facilities.h"
/// <summary>
///  参数要求a>0 b>a c>b
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns></returns>
int my_complicated_function(int a, int b, int c) {
	if (!(a > 0 && a < b && b < c)) error("bad arguments for mcf");
	return 0;
}
int main() {
	try {
		my_complicated_function(-1, 2, 3);
	}
	catch (exception &e) {
		cout << "exception :" << e.what() << endl;
	}
	return 0;
}
