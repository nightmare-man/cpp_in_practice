#define Graph
#ifdef Graph
#include "../include/Simple_window.h"
#include "../include/Graph.h"
using namespace Graph_lib;
#else
#include "../include/std_lib_facilities.h"
#endif
int main() {
	Circle cl{ Point{100,100},50 };
	Circle cl1 = cl;
}