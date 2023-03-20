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
	class Binary_tree :public Shape{
	public:
		Binary_tree(Point p, int level, int radius, int lengh, double degree) :l{ level }, r{ radius }, len{ lengh }, d{degree} {
			add(p);
			int amount = int(std::pow(2, level - 1)) - 1;
			int now_level = 0;
			for (int cnt = 0; cnt < amount; cnt++) {
				if (cnt == int(pow(2, now_level) - 1)) now_level++;
				get_next_points(point(cnt),int(lengh*pow(0.8,now_level)), degree * pow(0.6, now_level));
			}
		}
	
		void draw_lines() const override {
			if (l == 1) {
				fl_arc(point(0).x, point(0).y, r, r, 0, 360);
				return;
			}
			int amount = int(std::pow(2, l - 1)) - 1;
			
			for (int cnt = 0; cnt < amount; cnt++) {
				Point mid = point(cnt);
				Point left = point((cnt + 1) * 2 - 1);
				Point right = point((cnt + 1) * 2);
				
				fl_circle(left.x, left.y, r);
				fl_circle(right.x,right.y, r);
				fl_line(mid.x,mid.y ,left.x,left.y);
				fl_line(mid.x,mid.y, right.x, right.y);

			}
		}
	protected:
		int l;//层数
		int r;//节点半径
		int len;//连线长度
		double d;//开合角度
		void get_next_points(Point p,int lengh,double degree) {
			int x_span = lengh * std::sin(degree * _Pi / 360);
			int y_span = lengh * std::cos(degree * _Pi / 360);
			add(Point{ p.x - x_span,p.y + y_span });
			add(Point{ p.x + x_span,p.y + y_span });
		}
	};
	class Binary_tree_angle :public Binary_tree {
	public:
		Binary_tree_angle(Point p, int level, int radius, int lengh, double degree):Binary_tree(p,level,radius,lengh,degree) {};
		void draw_lines()const override {
			if (l == 1) {
				fl_arc(point(0).x, point(0).y, r, r, 0, 360);
				return;
			}
			int amount = int(std::pow(2, l - 1)) - 1;

			for (int cnt = 0; cnt < amount; cnt++) {
				Point mid = point(cnt);
				Point left = point((cnt + 1) * 2 - 1);
				Point right = point((cnt + 1) * 2);
				fl_rect(mid.x -r, mid.y-r, r+r, r + r);
				fl_rect(left.x - r, left.y - r, r + r, r + r);
				fl_rect(right.x - r, right.y - r, r + r, r + r);
				
				fl_line(mid.x, mid.y, left.x, left.y);
				fl_line(mid.x, mid.y, right.x, right.y);

			}
		}
	};
}
int main() {
	using namespace Graph_lib;
	Simple_window win{ Point{100,100},1000,600,"window" };
	Immobile_Cicle cl{ Point{100,100},50 };
	cl.set_color(Color::red);
	win.attach(cl);
	win.wait_for_button();
	cl.move(100, 0);
	win.wait_for_button();
	Binary_tree_angle bt{ Point{500,20},7,10,400,160 };
	bt.set_color(Color::red);
	win.attach(bt);
	win.wait_for_button();
	
}