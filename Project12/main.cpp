#include "../include/std_lib_facilities.h"
template<typename it1,typename it2>
it2 copy1(it1 f1,it1 e1,it2 f2) {
	//参数用的不是引用，原因在于传进来的可能是右值
	if (f1 == e1) return f2;
	for (auto x = f1; x != e1; x++) {
		*f2 = *x;
		f2++;
	}
	return f2;
}
int main() {
	int a[]{ 0,1,2,3,4,5,6,7,8,9 };
	vector<int> a1{ 0,1,2,3,4,5,6,7,8,9 };
	list<int> a2{ 0,1,2,3,4,5,6,7,8,9 };
	int b[10]{};
	std::copy(a, a + 10, b);
	vector<int> b1{ a1 };
	list<int> b2{ a2 };
	for (int i = 0; i < 10; i++) a[i] += 2;
	//注意这儿要使用引用，每次都从迭代器获取引用，而不是拷贝*iterator
	for (auto& p : a1)p += 3;
	for (auto& p1 : a2)p1 += 5;
	cout << a[0] << " " << a1[1] << " " << *a2.begin() << endl;
	copy1(a2.begin(), a2.end(), a1.begin());
	for (auto p : a1)cout << p << endl;
	auto p = find(a1.begin(), a1.end(), 8);
	if (p == a1.end()) cout << "没找到";
	else cout << "找到了，位置在" << p - a1.begin();

}