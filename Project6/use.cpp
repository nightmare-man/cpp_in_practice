#include "../include/std_lib_facilities.h"
class Date {
public:
	Date(int y1,int m1,int d1):y(y1),m(m1),d(d1) {}
	void print();
	void add_day(int n);
	int month() { return m; }
	int year() { return y; }
	int day() { return d; }
private:
	int y;
	int m;
	int d;
};
void Date::print() {
	cout << y << " " << m << " "<<d;
}
void Date::add_day(int n) {

}
int main() {
	Date d(19, 10, 20);
	d.print();
	return 0;
}