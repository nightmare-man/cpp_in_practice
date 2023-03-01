#include "../include/std_lib_facilities.h"
int main() {
	cout << "Expression:";
	int lval, rval;
	char op;
	cin >> lval;
	int result;
	bool end = false;
	while (!end&&cin >> op >> rval) {
		switch (op) {

		case '+':
			result = lval + rval;
			break;
		case '-':
			result = lval - rval;
			break;
		case '*':
			result = lval * rval;
			break;
		case '/':
			result = lval / rval;
			break;
		default:
			end = true;
			break;
		}
		lval = result;
	}
	cout << "Result:" << result << endl;
	return 0;
}