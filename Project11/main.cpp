#include "../include/std_lib_facilities.h"
void suspicious(int s, int x) {
	int* p = new int[s];
	//异常导致delete无法执行内存泄露
	error("nihao");
	delete[] p;
	return;
}
int main() {
	suspicious(100,200);
}