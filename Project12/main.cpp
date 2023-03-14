#include "../include/std_lib_facilities.h"
using Line = vector<char>;
struct Doc {
	list<Line> line;
	//构造函数添加空行
	Doc() { line.push_back(Line{}); }
};
istream& operator>>(istream& is, Doc& d) {
	//这里使用get而不是cin>> 后者会吞掉\n
	for (char ch; is.get(ch);) {
		d.line.back().push_back(ch);
		if (ch == '\n') d.line.push_back(Line{});
	}
	if (d.line.back().size()) d.line.push_back(Line{});
	return is;
}
ostream& operator<<(ostream& os, Doc d) {
	for (const auto p : d.line) {
		for (const auto x : p) cout << x;
	}
	return os;
}
int main() {
	Doc d;
	cin >> d;
	cout << d;
	return 0;
}