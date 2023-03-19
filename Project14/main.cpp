#include "../include/Simple_window.h"
#include "../include/Graph.h"
#include "Box.h"
namespace Graph_lib {
	//三种继承方式 public private protect
	//首先啊，这三种继承方式不影响派生类
	//内部对基类的访问，即如果基类的成员为
	//public protected 那不论那种继承方式
	//都能访问基类的成员
	//那影响什么呢？影响的是基类的成员被继承后的属性，的修饰符，即如果是private继承
	//那基类的public protected成员在派生类中成为了private的 
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
	Open_polyline op{ Point{100,100},Point{100,200} };

}