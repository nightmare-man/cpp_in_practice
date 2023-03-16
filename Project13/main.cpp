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
//函数对象，用成员作为内部参数--内部变量又称状态
//重载()运算符
//比起全局变量做函数内部参数更容易维护
//且方便生产一个函数的不同内部参数版本
class Large_than {
private:
	int val;
public:
	Large_than(int v) :val{ v } {};
	bool operator()(int x) { return x > val; }
};
int main() {
	vector<int> p{ 2,4,6 };
	//auto it = find_if1(p.begin(), p.end(), Large_than{6});
	//使用lambda表达式，代替函数对象
	//注意，除了stl算法部分，尽量
	//不使用函数对象和lambda
	//使用 c class stl就ok了
	auto it = find_if1(p.begin(), p.end(), [](int x) {return x > 5;
		});
	if (it == p.end()) cout << "not find";
	else cout << "find";
	cout << Large_than{ 6 }(10);
	return 0;
}