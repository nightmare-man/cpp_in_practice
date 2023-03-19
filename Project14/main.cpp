
#include <iostream>
using namespace std;
//彻底终结右值引用，为了实现移动语义:(转移资源所有权，自己不再使用)
//std::move 能将左值变为右值 实现左值的移动语义
//比如vector<string> v;string s="123",v.push(move(s))
//这里为啥要将左值变为右值呢，为了实现移动语义
//v.push_back里有一个赋值，如果是用常量左值引用
//那么将调用深拷贝，如果是用右值引用，则调用移动赋值，成本更低
//但缺点是，s不再指向"123"(毕竟移动了)

//其余的时候，成本低就传值  成本高就引用，不让改就常量引用
class A {
public:
	A(int a1) :a{a1} {
		cout << "参数构造\n";
	};
	A() :a{ 0 } {
		cout << "默认构造\n";
	};
	A(const A& x) :a{ x.a } {
		cout << "拷贝构造\n";
	};
	A(A&& x)noexcept:a{ x.a } {
		x.a = 0;
		cout << "移动构造\n";
	};
	int get_a() const{ return a; }
private:
	int a;
};
A get_p() {
	A a;
	return a;
}
void f( A x) {
	cout <<x.get_a();
}
void f1(const A& x) {
	
}
void f2(A& x) {
	cout << x.get_a();
}
int main() {
	

}