#include "../include/std_lib_facilities.h"
int area(int lengh, int width);
int framed_area(int lengh, int width);
int main() {
	int area1 = area(3, 0);
	if (area1 <= 0) error("non-positive area");
	return 0;
}
int area(int lengh, int width) {
	if (lengh <= 0 || width <= 0) return -1;
	return lengh * width;
}
int framed_area(int length, int width) {
	constexpr int frame_width = 2;
	if (length - frame_width <= 0 || width - frame_width <= 0)
		error("non-positive area() called by framed_area()");
	return (length - 2)*( width - 2);
}
