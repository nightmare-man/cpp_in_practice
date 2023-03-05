#include "../include/std_lib_facilities.h"
constexpr int not_a_reading = -7777;
constexpr int not_a_month = -1;
struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };//vector个数用（）
	//如果个数会被识别成元素时用（）否则{}
};
struct Month {
	int month{ not_a_month };
	vector<Day>day{32};
};
struct Year {
	int year;
	vector<Month> month{ 12 };
};
struct Reading {
	int day, hour;
	double temperature;
};
istream& operator>>(istream& is, Reading& r) {
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d, h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') error("bad reading");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}
vector<string> vs{ "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec" };
int month_to_int(string mm) {
	
	for (int i = 0; i < vs.size();i++ ) {
		if (vs[i] == mm) return i+1;
	}
	return -1;
}
void end_of_loop(istream& is, char term, string message) {
	if (is.fail()) {
		is.clear();
		char ch;
		if (is >> ch && ch == term) return;
		error(message);
	}
}
bool is_valid(const Reading& r) {
	if (r.day < 1 || r.day>31) return false;
	if (r.hour < 0 || r.hour>23) return false;
	if (r.temperature < -80 || r.temperature>100) return false;
	return true;
}
istream& operator>>(istream& is, Month& m) {
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	string month_maker;
	string mm;
	is >> month_maker >> mm;
	if (!is || month_maker != "month") error("bad start of month\n");
	m.month = month_to_int(mm);
	int duplicates = 0;
	int invalid = 0;
	for (Reading r; is >> r;) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading) ++duplicates;
		}
		else invalid++;
	}
	if (invalid) error("invalid readings in month", invalid);
	if (duplicates) error("duplicates readings in month", duplicates);
	
	return is;
}
int main() {
	Month m;
	cin >> m;
}