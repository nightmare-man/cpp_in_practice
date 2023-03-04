#include "../include/std_lib_facilities.h"
void fibonacci(int x,int y,vector<int>& v,int n) {
	if (n < 2) error("bad argument\n");
	int a = x;
	int b = y;
	int c =0 ;

	for (int i = 0; i < n-2; i++) {
		v.push_back(a);
		c = a + b;
		a = b;
		b = c;
	}
}
void print(string tag,const vector<int>& v) {
	cout << tag << ":";
	for (int x : v)cout << x<< " ";
}
int main() {
	vector<int> vint;
	fibonacci(1, 1, vint, 100);
	print("vector is", vint);
	return 0;
}