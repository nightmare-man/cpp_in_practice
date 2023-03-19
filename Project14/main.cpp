#include "../include/Simple_window.h"
#include "../include/Graph.h"
#include "Box.h"
namespace Graph_lib {
	//三种继承方式 public private protected
	//继承的默认规则，private
	//派生类不能访问 基类中的private成员，但可以访问public protected成员
	//但派生类继承的基类的public protected成员 也变为private
	//即不能 用"派生类的对象"访问基类的public protected成员

	//如果这里不加public 那么默认private继承，那么win.attach(arc)就报错，因为无法用arc来访问基类的public protected对象了，导致attach内部无法工作
	//因此需要用public修饰
	//struct默认是public继承 class是默认private继承
	//前者默认成员是public 后者默认private
	struct Arc : Shape {
	public:
		Arc(Point p1, int w1, int h1, double s1, double e1) :w{ w1 }, h{ h1 }, s{ s1 }, e{ e1 } {
			add(p1);
		}
		void draw_lines()const;
	private:
		int w;
		int h;
		double s;
		double e;
	};
	void Arc::draw_lines()const {
		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, w, h, s, e);
		}
	}
}
//attach是引用 add是传值
//因此，当t出作用域被销毁时，会报错
void f(Simple_window& win) {
	using namespace Graph_lib;
	Text t{ Point{100,100},"hello" };
	t.set_color(Color::blue);
	win.attach(t);
	win.wait_for_button();
}
int main() {
	using namespace Graph_lib;
	Simple_window win{ Point{100,100},500,500,"window" };
	Graph_lib::Box bbox{ Point{100,100},300,300,100,100 };
	bbox.set_color(Color::red);
	win.attach(bbox);
	win.wait_for_button();
	Open_polyline op{  };
	op.add(Point{ 00,00 });
	op.add(Point{ 150,200 });
	op.set_color(Color::blue);
	win.attach(op);
	f(win);
	win.wait_for_button();
}