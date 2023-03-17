#include "../include/std_lib_facilities.h"
struct Item {
	string name;
	int iid;
	double value;
};
istream& operator>>(istream& in,Item& v) {
	in >> v.name >> v.iid >> v.value;
	//if (!in) error("bad input");
	return in;
}
ostream& operator<<(ostream& os, const Item& v) {
	os << "{" << v.name << "," << v.iid << "," << v.value << "}\n";
	return os;
}
int main() {
	string from;
	cin >> from;
	if (!cin)error( "no input" );
	ifstream is{ from };
	vector<Item> x;
	if (!is) error("open file error");
	while (true) {
		Item p;
		is >> p;
		if (!is) break;
		x.push_back(p);
	}
	x.insert(x.begin(), Item{ "horse shoe",99,12.34 });
	x.insert(x.begin(), Item{ "Canon S400",9988,499.95 });
	x.erase(find_if(x.begin(), x.end(), [](Item i) {return i.name == "Canon S400"; }));
	sort(x.begin(), x.end(), [](const Item& a, const Item& b) {
		return a.value > b.value;
		});
	for (auto p : x) {
		cout << p;
	}
	return 0;
}