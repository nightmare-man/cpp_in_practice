#include "../include/std_lib_facilities.h"
int main() {
	string number[5]{ "zero","one","two","three","four" };
	string current{ "" };
	while (cin >> current) {
		bool find = false;
		for (int i = 0; i < 5; i++) {
			if (current == number[i]) {
				cout << i<<"\n";
				find = true;
				break;
			}
			
		}
		if (!find) cout << "stupid computer\n";
	}
}