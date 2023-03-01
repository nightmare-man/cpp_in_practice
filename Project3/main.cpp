#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<int> prime = { 2,3,5 };
	constexpr int end = 1000000;
	for (int i = 6; i <= end; i++) {
		double max = sqrt(i);
		bool isPrime = true;
		for (int j = 0; j < prime.size()&&prime[j]<=max; j++) {
			if (i % prime[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) prime.push_back(i);
	}
	for (int i : prime) cout << i << endl;
	return 0;
}
int square(int x) {
	return x * x;
}