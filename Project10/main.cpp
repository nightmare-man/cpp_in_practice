#include "../include/std_lib_facilities.h"
double* calc(int res, int max) {
	//p用于局部使用，但是忘记释放
	double* p = new double[max];
	double* res1 = new double[res];
	return res1;
}
int main() {
	double* t = calc(100, 100);
	return 0;
}