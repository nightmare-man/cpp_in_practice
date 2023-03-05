
#include "Chrono.h"
namespace Chrono {//表示仍在Chrono作用域内
	Date::Date(int yy, Month mm, int dd):y(yy),d(dd),m(mm) {
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	const Date& default_date() {
		static Date dd{ 2001,Month::jan,1 };
		return dd;
	}
	Date::Date() : y{ default_date().year() }, m(default_date().month()), d{default_date().day()} {

	}
	void Date::add_day(int n) {

	}
	void Date::add_month(int m) {

	}
	void Date::add_yeaer(int y) {

	}
	bool is_date(int y, Month m, int d) {
		return true;
	}
	bool leapyear(int y) {
		return false;
	}
	bool operator==(const Date& a, const Date& b) {
		return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);//利用已有的==操作符
	}
	std::ostream& operator<<(std::ostream& os, const Date& a) {
		os << a.year() << " " << int(a.month()) << " " << a.day();
		return os;
	}
	std::istream& operator>>(std::istream& is, Date& a) {
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
			is.clear(std::ios_base::failbit);
			//设置failbit
			return is;
		}
		a = Date(y, Month(m), d);
		return is;
	}
}