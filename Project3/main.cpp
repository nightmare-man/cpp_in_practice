#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	int max = 100;
	int min = 1;
	int mid = 0;
	while (max > min) {
		mid = (max + min) / 2;
		cout << "is ur number smaller than " << mid << " ?\n";
		string in = "";
		cin >> in;
		if (in == "y") max = mid-1;
		else if(in == "n") min = mid;
	}
	cout << "ur number is " << max;
	return 0;
}
int square(int x) {
	return x * x;
}