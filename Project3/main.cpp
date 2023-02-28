#include "../include/std_lib_facilities.h"
int square(int x);
int main() {
	vector<double> temps;
	//内置类型 如果是局部变量不会初始化 全局变量会初始化
	//而自定义类型 一定会默认初始化
	for (double cur; cin >> cur;) {
		temps.push_back(cur);
	}
	cout << "input end\n";
	sort(temps);
	for (double s : temps) {
		cout << s << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}