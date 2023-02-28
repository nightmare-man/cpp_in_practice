#include "../include/std_lib_facilities.h"
int main() {
	int i = 0;
	while (i < 26) {
		cout << char('a' + i) << " " << int('a' + i) << endl;
		i++;
	}
	return 0;
}