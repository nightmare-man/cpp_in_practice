#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<int> prime = { 2,3,5 };
	constexpr int end = 1000;
	for (int i = 6; i <= end; i++) {
		bool isPrime = true;
		for (int x : prime) {
			if (i % x == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) prime.push_back(i);
	}
	for (int x : prime) {
		cout << x << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}