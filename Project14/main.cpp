#define Graph
#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
#else
#include "../include/std_lib_facilities.h"
#endif
namespace Graph_lib {
	class Immobile_Cicle :public Circle {
	public:
		Immobile_Cicle(const Point& p, int r) :Circle(p, r) {};
		void move(int dx,int dy)override {
			return;
		}
	};
}
int main() {
	using namespace Graph_lib;
	Simple_window win{ Point{100,100},500,500,"window" };
	Immobile_Cicle cl{ Point{100,100},50 };
	cl.set_color(Color::red);
	win.attach(cl);
	win.wait_for_button();
	cl.move(100, 0);
	win.wait_for_button();
	
}