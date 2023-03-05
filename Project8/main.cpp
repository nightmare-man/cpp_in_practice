#include "../include/std_lib_facilities.h"
struct Reading {
	int hour;
	double temperature;
};
int main() {
	cout << "Please enter input file name:";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)error("can't open file:", iname);
	string oname;
	cout << "Please enter output file name:";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open file:", oname);
	vector<Reading> temps;
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		if (hour < 0 || hour>23) error("hour out of range");
		temps.push_back(Reading{ hour,temperature });
	}
	for (Reading x : temps) {
		ost << '(' << x.hour << ',' << x.temperature << ")\n";
	}
	//不用显示调用ist.open 和close 超过了流的作用域，文件自动关闭（析构函数里）
	return 0;
}