#include "../include/std_lib_facilities.h"
template<typename it,typename T>
it find1(it start, it end, const T& val) {
	while (start != end && (*start != val)) start++;
	return start;
}
//传入函数指针
template<typename it,typename Fun>
it find_if1(it start, it end, Fun f) {
	while (start != end && !f(*start)) start++;
	return start;
}
bool odd(int x) {
	return x % 2;
}
//函数对象，用成员作为内部参数
//重载()运算符
//比起全局变量做函数内部参数更容易维护
class Large_than {
private:
	int val;
public:
	Large_than(int v) :val{ v } {};
	bool operator()(int x) { return x > val; }
};
int main() {
	vector<int> p{ 2,4,6 };
	auto it = find_if1(p.begin(), p.end(), Large_than(6));
	if (it == p.end()) cout << "not find";
	else cout << "find";
	return 0;
}