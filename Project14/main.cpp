#include <FL/Fl.h>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>
int main() {
	Fl_Window window(200, 200, "Window titile");
	Fl_Box box(0, 0, 200, 200, "hey i am here");
	window.show();
	return Fl::run();
}



