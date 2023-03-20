
#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
#else
#include "../include/std_lib_facilities.h"
#endif
//虚函数实现原理
//基类成员实际有一个函数指针vptr 指向一个虚函数表
//基类中所有虚函数的地址都在该表中
//派生类由于继承了基类，因此也获得了基类成员(包括vptr)
//但是其实例的vptr指向的是自己的虚函数表
//派生类的虚函数表中，没有覆盖的虚函数与基类的一样
//覆盖了的就是对应的覆写函数的地址
class B1 {
public:
	virtual void vf1() {
		cout << "B1::vf1\n";
	};
	virtual void vf2() {
		cout << "B1::vf2\n";
	};
	void f() {
		cout << "B1::f\n";
	}
};
class D1 :public B1 {
public:
	void vf1()override {
		cout << "D1::vf1\n";
	};
	void f() {
		cout << "D1::f\n";
	}
};
class D2 :public B1 {
	void vf2() override{
		cout << "D2::vf2\n";
	}
	void f() {
		cout << "D2::f\n";
	}
};
int main() {
	B1 b;
	D1 d1;
	D2 d2;
	b.vf1();//b作为基类的实例化，vptr指向基类的虚函数表
	b.vf2();//基类的虚函数表里都记录的都是基类的虚函数地址

	d1.vf1();//d1作为派生类D1的实例化，vptr指向派生类的虚函数表
	d1.vf2();//D1的虚函数表里vf1的地址覆写为D1自己的 vf2的没被覆写

	B1& ref = d1;//ref是d1的引用，但被解释为B1,因此被截断，只剩下
	//基类成员 包括vptr
	ref.vf1();//ref作为派生类D1实例化后截断的结果，vptr仍然指向D1
	//的虚函数表，因此虚函数的绑定和D1的派生类一样
	ref.f();//但是非虚函数则是从派生类中调用同名同参数的。
	//因此会输出B1::f
}