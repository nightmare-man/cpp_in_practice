#include "../include/std_lib_facilities.h"
/// <summary>
///参数要求a>0 b>a c>b
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns></returns>
int my_complicated_function(int a, int b, int c) {
	if (!(a > 0 && a < b && b < c)) error("bad arguments for mcf");
	return 0;
}
/// <summary>
///length>0 width>0
/// </summary>
/// <param name="lengh"></param>
/// <param name="width"></param>
/// <returns></returns>
int area(int lengh, int width) {
	//if (lengh <= 0 || width <= 0) error("bad arguments");
	int a = lengh * width;
	if (a <= 0) error("area() pose-condition");
	return a;
}
int main() {
	try {
		my_complicated_function(-1, 2, 3);
		area(-1, -1);
	}
	catch (exception &e) {
		cout << "exception :" << e.what() << endl;
	}
	return 0;
}
