#include "../include/std_lib_facilities.h"
class Date {
public:
	class Invalid {};
	Date(int y1, int m1, int d1);
	void print();
	void add_day(int n);
	int month() { return m; }
	//成员函数定义放在类定义内 成为内联，但缺点是当函数改变时
	//所有引用该类的地方都要重新编译
	int year() { return y; }
	int day() { return d; }
private:
	bool is_valid();
	int y;
	int m;
	int d;
};
Date::Date(int y1, int m1, int d1):y(y1),m(m1),d(d1) {
	if (!is_valid())throw Invalid{};
}
bool Date::is_valid() {
	if (m < 1 || m>12) return false;
	if (d < 1 || d>30) return false;
	if (y < 1990) return false;
	return true;
}
void Date::print() {
	cout << y << " " << m << " "<<d;
}
void Date::add_day(int n) {

}
enum class Month {
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};
enum Day {
	Mon=1,Tue,Wed,Thu
};
Month operator++(Month& m) {
	m = (m == Month::dec )?Month::jan:Month(int(m) + 1);
	//可以将枚举类型转化成int
	//也可以通过Month(int) 构造枚举
	return m;
}
int operator+(int a, int b) {

}
int main() {
	Month m = Month::dec;
	++m;
	cout<<int(m);

	return 0;
}