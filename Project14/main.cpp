#include "../include/Simple_window.h"
#include "../include/Graph.h"

int main() {
	using namespace Graph_lib;
	Simple_window win{ Point{200,200},500,500,"Color Style" };
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 20,j * 20},20,20 });
			vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
			win.attach(vr[vr.size() - 1]);
		}
	}
	win.wait_for_button();
}