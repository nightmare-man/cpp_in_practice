#include "../include/Simple_window.h"
#include "../include/Graph.h"
int main() {
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,600,400,"canvas" };
	//显示当前，等待点击button后继续执行
	win.wait_for_button();

	Axis xa{ Axis::x,Point{20,300},280,10,"x axis" };
	xa.set_color(Color::red);
	win.attach(xa);
	win.set_label("A1");
	win.wait_for_button();

	Axis ya{ Axis::y,Point{20,300},280,10,"y axis" };
	ya.set_color(Color::blue);
	win.attach(ya);
	win.set_label("A2");
	win.wait_for_button();

	Function sine{ sin,0,100,Point{20,150},1000,50,50 };
	win.attach(sine);
	win.set_label("A3");
	win.wait_for_button();
}
