#include "../include/std_lib_facilities.h"
int main() {
	cout << "Please enter an integer in the range 1to 10:\n";
	int n = 0;
	while (true) {
		cin >> n;
		if (cin) {
			if (n >= 1 && n <= 10) break;
			cout << "Sorry wrong range;\n";
		}
		else if (cin.fail()) {
			//读到非数字 重置输入流试图读取
			cin.clear();
			cout << "sorry,not a number try again:\n";
			for (char ch; cin >> ch && !isdigit(ch);) {

			}
			//遇到了eof或者磁盘故障
			if (!cin) error("no input");
			cin.unget();
			//读到了数字将数字放回，下一次循环读入
		}
		else {
			error("no input");
		}
	}
	cout << "n is " << n << endl;
}