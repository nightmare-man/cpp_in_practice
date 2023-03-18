#include "../include/Simple_window.h"
#include "../include/Graph.h"
struct Mys {
	explicit Mys(int x1, int y1) :x{ x1 }, y{ y1 } {};
	int x;
	int y;
};
int main() {
	Point tl{ 10,100 };
	Simple_window win{ tl,500,500,"window" };
	Lines x;
	for (int i = 1; i < 25; i++) {
		x.add( Point{0,i * 20},Point{500,i * 20} );
	}
	Lines y;
	for (int i = 1; i < 25; i++) {
		y.add(Point{ i * 20,0 }, Point{ i * 20,500 });
	}
	//隐式类型转换，
	pair<int, int> a = { 1,2 };
	//隐式类型转换
	Mys s = { 1,2 };
	x.set_color(Color::red);
	y.set_color(Color::green);
	win.attach(y);
	win.attach(x);
	win.wait_for_button();
}