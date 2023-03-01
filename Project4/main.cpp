#include "../include/std_lib_facilities.h"
int area(int lenght, int width);
int main() {
	char s1 = area(100,100);
	cout << s1;
	return 0;
}
int area(int lenght, int width) {
	return lenght * width;
}
