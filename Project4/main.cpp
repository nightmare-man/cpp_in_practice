#include "../include/std_lib_facilities.h"
void trySettle(double a, double b, double c, double& a1, double& a2) {
	int flag = b * b - 4 * a * c;
	if(flag< 0)error("bad arguments for trySettle()\n");
	a1 = -b + sqrt(flag);
	a2 = -b - sqrt(flag);
	a1 /= 2 * a;
	a2 /= 2 * a;
}
int main() {
	double a, b, c;
	double a1, a2;
	try {
		cin >> a >> b >> c;
		trySettle(a, b, c, a1, a2);
	}
	catch (exception& e) {
		cout << "exception :" << e.what() << endl;
	}
	cout << "answer:" << a1 << " " << a2 << endl;
	return 0;
}
