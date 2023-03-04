#include "my.h"
void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swap_r(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	const int x = 7;
	const int y = 9;
	swap_r(x, y);
	print(x);
	print(y);
	return 0;
}