#include "../include/std_lib_facilities.h"
class Name_value {
public:
	string name;
	int value;
	Name_value(string n, int v) :name(n), value(v) {

	};
};
int main() {
	vector<Name_value> data;
	string name = "";
	int value = 0;
	while (cin >> name >> value) {
		for (Name_value x : data) {
			if (x.name == name) error("repeated name\n");
		}
		data.push_back(Name_value(name, value));
	}
	for (Name_value x : data) {
		cout << "name:" << x.name << " value:" << x.value << endl;
	}
	return 0;
}
int square(int x) {
	return x * x;
}