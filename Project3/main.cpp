#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	double source1 = 0;
	double source2 = 0;
	double result = 0;
	char op = ' ';
	cout << "enter two number and one operator + - * / %:\n";
	cin >> source1 >> source2;
	cin >> op;
	switch (op)
	{
	case '+':
		result = source1 + source2;
		break;
	case '-':
		result = source1 - source2;
		break;
	case '*':
		result = source1 * source2;
		break;
	case '/':
		result = source1 / source2;
		break;
	case '%':
		result = int(source1) % int(source2);
	default:
		break;
	}
	cout << source1 << " " << op << " " << source2 << " = " << result;
	return 0;
}
int square(int x) {
	return x * x;
}