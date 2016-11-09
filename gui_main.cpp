#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_ask.H>

//
//	widgets
//

Fl_Window *win;

//
//	main
//

int main() {
	const int X = 640;
	const int Y = 480;
	
	// create a window
	win = new Fl_Window(X, Y, "robotree");
	
	// enable resizing
	win->resizable();
	
	win->end();
	win->show();
	return(Fl::run());
}
