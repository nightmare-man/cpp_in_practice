#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
using namespace Graph_lib;
#else
#include "../include/std_lib_facilities.h"
#endif
class B2 {
public:
	//纯虚函数
	virtual void pvf() = 0;
};
class B3 {
protected:
	B3();
};
int main() {
	B2 b;//不允许定义抽象类的实例
	B3 b;
}