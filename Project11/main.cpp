#include "../include/std_lib_facilities.h"
vector<int>* make_vec() {
	//unique_ptr可以保证当p这个指针变量被销毁时，指向的对象
	//一并销毁，释放内存
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(1);
	//p.release()会将p指向nullptr 同时返回原本指向的地址
	//这样对象就不会被销毁，地址也能返回
	//当中间有异常发生时，由于没有执行release，p会被析构
	//p指向的对象也会被析构，不存在内存泄露
	return p.release();
}
unique_ptr <vector<int>> make_vec1() {
	unique_ptr <vector<int>> p{ new vector<int> };
	//实际使用的是移动赋值函数，因此返回后p将不再指向
	//分配的内存对象，被析构时也不会一并析构该对象
	return p;
}
//既然用了移动构造，还不如直接移动vector<int>
//将mem赋值给了p2,自己变为0
vector<int> make_vec2() {
	vector<int> p1;
	p1.push_back(33);
	return p1;
}
int main() {
	vector<int>* p = make_vec();
	cout << (*p)[0];
	delete p;
	unique_ptr<vector<int>> q = make_vec1();
	//相比上一个不需要显示delete
	vector<int>* p1 = q.release();
	p1->push_back(2);
	cout << (*p1)[0];
	vector<int> p2 = make_vec2();
	cout << p2[0];
	return 0;
}