#pragma once
#include "../include/Graph.h"
namespace Graph_lib {
	struct Box: Shape
	{
		Box(Point p, int w1, int h1, int w2, int h2) :lw{ w1 }, lh{ h1 }, ew{ w2 }, eh{ h2 } { add(p); }
		void draw_lines()const;
	private:
		int lw;
		int lh;
		int ew;
		int eh;
	};
	
}


