
#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
#else
#include "../include/std_lib_facilities.h"
#endif
class B {
public:
	virtual void f() const {
		cout << "B::F()\n";
	}
	void g()const {
		cout << "B::g()\n";
	}
};
class D:public B {
public:
	//添加override 显示表明重写 覆盖
	 void f() const override {
		cout << "D::F()\n";
	}
	void g()const {
		cout << "D::g()\n";
	}
};
class DD:public D {
public:
	//DD继承了D D继承了B  当dd作为B的对象是，用的是D重写的f
	void f()  {
		cout << "DD::F()\n";
	}
	void g()const {
		cout << "DD::g()\n";
	}
};
void call(const B& b) {
	b.f();
	b.g();
}
int main() {
	B b;
	D d;
	DD dd;

	call(b);//B::f B::g
	call(d);//D::f B::g
	call(dd);//B::f B::g //wrong D::f B::g 原因是继承了D的f

	b.f(); //B::f
	b.g();//B::g

	d.f();//D::f
	d.g();//D::g

	dd.f();//DD::f
	dd.g();//DD::g
}