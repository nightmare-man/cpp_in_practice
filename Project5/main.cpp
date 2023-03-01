#include "../include/std_lib_facilities.h"
int main() {
	cout << "Expression:";
	int lval, rval;
	char op;
	cin >> lval >> op >> rval;
	int result;
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
			result = 0;
			break;
	}
	cout << "Result:" << result << endl;
	return 0;
}