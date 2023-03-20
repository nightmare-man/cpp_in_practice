
#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
#else
#include "../include/std_lib_facilities.h"
#endif
class B1 {
public:
	virtual void vf() {
		cout << "B1::vf\n";
	};
	void f() {
		cout << "B1::f\n";
	};
};
class D1 :public B1 {
public:
	void vf()override {
		cout << "D1::vf\n";
	};
	void f() {
		cout << "D1::f\n";
	}
};
int main() {
	//纯虚函数才是抽象类 无法实例化
	//这儿只有一个虚函数
	B1 b;
	b.vf();
	b.f();
	
	D1 d;
	d.vf();
	d.f();//D1::f

	B1& b1 = d;
	//实际是一个d因此调用d对vf的重载
	//引用实际是一个指针常量
	b1.vf(); // 除了虚函数或按照其实际派生类型
	//来执行，其余函数都看其按照什么类型解释
	b1.f();//D1::f  //错了这儿是B1::f
}