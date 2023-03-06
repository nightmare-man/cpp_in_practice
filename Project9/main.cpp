#include "../include/std_lib_facilities.h"
int main() {
	int a, b, c, d;
	//用10进制输入a 16进制输入b 8进制输入cd
	cin >> a >> hex >> b >> oct >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
	//每种操作符都是持久的，除非显示解除
}