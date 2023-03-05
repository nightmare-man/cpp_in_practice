#include "../include/std_lib_facilities.h"
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m) {
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	//可以将枚举类型转化成int
	//也可以通过Month(int) 构造枚举
	return m;
}
class Year {
	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) :y(x) { if (x<min || x>=max )throw Invalid{}; }
	int year() { return y; }
private:
	int y;
};
class Date {
	
public:
	class Invalid {};
	Date() :y(Year(1990)), m(Month::jan), d(1) {};
	//因为有其他构造函数，所以编译器不会提供默认构造函数
	//因此需要自己提供
	Date(Year y1, Month m1, int d1);
	void print();
	void add_day(int n);
	Month month() { return m; }
	//成员函数定义放在类定义内 成为内联，但缺点是当函数改变时
	//所有引用该类的地方都要重新编译
	int year() { return y.year(); }
	int day() { return d; }
private:
	bool is_valid();
	Year y;
	Month m;
	int d{ 1 };//类内初始化
};
Date::Date(Year y1, Month m1, int d1):y(y1),m(m1),d(d1) {
	if (!is_valid())throw Invalid{};
}
bool Date::is_valid() {
	if (d < 1 || d>30) return false;
	return true;
}
void Date::print() {
	cout << y.year() << " " <<int(m) << " "<<d;
}
void Date::add_day(int n) {

}


int main() {
	vector<Date> d(10);
	for (Date x : d) {
		x.print();
	}
}