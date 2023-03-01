#include "../include/std_lib_facilities.h"
int area(int lengh, int width);
int framed_area(int lengh, int width);
int main() {
	int x = -1;
	int y = 2;
	int z = 4;
	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	cout << area3;
	double ratio = double(area1) / area3;
	cout << ratio;
	return 0;
}
int area(int lengh, int width) {
	return lengh * width;
}
int framed_area(int length, int width) {
	constexpr int frame_width = 2;
	if (length - frame_width <= 0 || width - frame_width <= 0)
		error("non-positive area() called by framed_area()");
	return (length - 2)*( width - 2);
}
