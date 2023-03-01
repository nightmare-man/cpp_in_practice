#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	constexpr int tar = 1000000000;
	double cur_num = 1;
	int spot = 1;
	double sum=0;
	while (spot <= 64) {
		sum += cur_num;
		cout << "spot " << spot << " cur " << cur_num << " sum " << sum << endl;
		spot++;
		cur_num *= 2;
	}
	return 0;
}
int square(int x) {
	return x * x;
}