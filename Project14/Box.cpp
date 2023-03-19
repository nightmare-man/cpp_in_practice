#include "Box.h"
namespace Graph_lib {
	void Box::draw_lines()const {
		if (ew * 2 > lw || eh * 2 > lh) return;
		if (!color().visibility()) return;
		Point left_top{ point(0) };
		Point left_bottom{ left_top.x,left_top.y + lh };
		Point right_top{ left_top.x + lw,left_top.y };
		Point right_bottom{ right_top.x,right_top.y + lh };
		fl_line(left_top.x, left_top.y + eh, left_bottom.x, left_bottom.y - eh);
		fl_line(right_top.x, right_top.y + eh, right_bottom.x, right_bottom.y - eh);
		fl_line(left_top.x + ew, left_top.y, right_top.x - ew, right_top.y);
		fl_line(left_bottom.x + ew, left_bottom.y, right_bottom.x - ew, right_bottom.y);
		fl_arc(left_top.x, left_top.y, ew+ew, eh+eh, 90, 180);
		fl_arc(right_top.x - ew * 2, right_top.y, ew+ew, eh+eh, 0, 90);
		fl_arc(left_bottom.x, left_bottom.y - eh * 2, ew+ew, eh+eh, 180, 270);
		fl_arc(right_bottom.x - ew * 2, right_bottom.y - eh * 2, ew+ew, eh+eh, 270, 360);
	}
}
