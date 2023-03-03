#include "../include/std_lib_facilities.h"
int factoral(int x) {
	if (x < 0) error("bad argument in factoral()\n");
	if (x == 0) return 1;
	int sum = 1;
	for (int i = 1; i <= x; i++) sum *= i;
	return sum;
}

/// <summary>
/// a>=b>0
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int Pab(int a,int b) {
	if (a < b || b <= 0) error("bad argument in Pab()\n");
	int sum = 1;
	for (int i = 0; i < b; i++) {
		sum *= (a - i);
	}
	return sum;
}
int main() {
	int a = 0, b = 0;
	char flag = 'x';
	int result = 0;
	cout << "enter two int a,b a>=b>0,p or c:\n";
	cin >> a >> b >> flag;
	switch (flag)
	{
	case 'p':
		result = Pab(a, b);
		break;
	case 'c':
		result = Pab(a, b) / factoral(b);
		break;
	default:
		break;
	}
	cout << "result:" << result << endl;
	return 0;
}