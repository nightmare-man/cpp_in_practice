#include "../include/Simple_window.h"
#include "../include/Graph.h"
namespace Graph_lib {
	//三种继承方式 public private protected
	//继承的默认规则，private
	//派生类不能访问 基类中的private成员，但可以访问public protected成员
	//但派生类继承的基类的public protected成员 也变为private
	//即不能 用"派生类的对象"访问基类的public protected成员
	
	//如果这里不加public 那么默认private继承，那么win.attach(arc)就报错，因为无法用arc来访问基类的public protected对象了，导致attach内部无法工作
	//因此需要用public修饰
	class Arc :public Shape {
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

int main() {
	Simple_window win{ Point{100,100},500,500,"window" };
	Graph_lib::Arc arc{ Point{100,100},50,50,0,90 };
	arc.set_color(Color::red);
	win.attach(arc);
	win.wait_for_button();
}