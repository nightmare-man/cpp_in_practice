#include "../include/std_lib_facilities.h"
int main() {
	//hex oct dec 16 8 10进制操作符
	cout << 1234 << " hex:" << hex << 1234 << " oct:" << oct << 1234;
	//showbase 显示16 8进制前缀
	cout << showbase << hex << 1234;
}