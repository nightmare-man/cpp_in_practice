#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<string> number = { "zero","one","two","three","four"\
	,"five","six","seven","eight","nine" };
	string in = "";
	while (cin >> in) {
		if (in.length() > 1) {
			for (int i = 0; i<number.size(); i++) {
				if (number[i] == in) {
					cout << i<<endl;
					break;
				}
			}
		}
		else {
			char a = in[0];
			int x = a - '0';
			cout << number[x]<<endl;
		}
	}
	return 0;
}
int square(int x) {
	return x * x;
}