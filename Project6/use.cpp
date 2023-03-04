#include "../include/std_lib_facilities.h"
void print(string tag, vector<int>& v) {
	cout << tag << ":";
	for (int x : v)cout << x<< " ";
}
int main() {
	vector<int> vint{ 1,2,3,4,5,6,7 };
	print("vector is", vint);
	return 0;
}