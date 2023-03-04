#include "../include/std_lib_facilities.h"
class Date {
public:
	Date(int y,int m,int d):year(y),month(m),day(d) {}
	void print();
private:
	int year;
	int month;
	int day;
};
void Date::print() {

}
int main() {
	Date d;
	d.print();
	return 0;
}