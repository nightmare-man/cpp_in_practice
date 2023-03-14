#include "../include/std_lib_facilities.h"
void copy(int* f1, int* e1, int* f2) {
	if (f1 == e1) return;
	for (; f1 != e1; ) {
		*f2 = *f1;
		f1++;
		f2++;
	}
}
//迭代器 指向序列中的某个元素，可以做一系列操作
//可以是指针 也可以是引用等
//泛型比较
template<typename Iterator> //要求传入的类型为容器类型
Iterator high(Iterator s,Iterator e) {
	Iterator h = s;
	for (; s != e; s++) {
		if (*s > *h)h = s;
	}
	return h;
}
int main() {
	//迭代器 iterator类
	vector<int> p{ 1,2,3,44,4,5 };
	vector<int>::iterator a = high(p.begin(), p.end());
	cout << *a;
	return 0;
}