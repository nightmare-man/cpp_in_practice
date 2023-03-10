#include "../include/std_lib_facilities.h"
int main() {
	int  *a= new int;

	*a = 10990;
	int* b = new int;
	*b = 10;
	int c=(*a)/(*b);
	cout << a;
	cout << b;
	cout << &c;
	while (true) {

	}
	return 0;
}