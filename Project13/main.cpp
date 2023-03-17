#include "../include/std_lib_facilities.h"
struct Item {
	string name;
	int iid;
	double value;
	//类内重载
	bool operator<(const Item&a);
	//也可以用friendly 类外重载，这样需要传
	//两个参数，因为不再默认传入this指针
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
bool Item::operator<(const Item&a) {
	return name > a.name;
}
int main() {
	string from;
	cin >> from;
	if (!cin) error("not input filename\n");
	ifstream is{ from };
	if (!is) error("can't open file");
	istream_iterator<Item> begin{ is };
	istream_iterator<Item> end{};
	//直接使用流迭代器初始化容器，相当于一直从输入流读Item
	list<Item> lll{ begin,end };
	//sort需要支持[]的随机访问迭代器，list不提供
	//sort(lll.begin(), lll.end());
	//使用list.sort需要重载运算符> <
	lll.sort();
	for (auto x : lll) cout<<x;
} 