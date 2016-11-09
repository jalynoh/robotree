#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
//
//	widgets
//

Fl_Window *win;
Fl_Tabs *tabs;
Fl_Group *tab1;
Fl_Group *tab2;

//
//	main
//

int main() {
	// create a window
	win = new Fl_Window(640, 480, "robotree");
	{
		// tabs container
		tabs = new Fl_Tabs(10, 10, 500-20, 200-20);
		{
			// tab 1
			 tab1 = new Fl_Group(10, 35, 500-20, 200-45, "main");
			{
				// stuff goes here for tab 1
			}
			tab1->end();
			
			// tab 2
			tab2 = new Fl_Group(10, 35, 500-10, 200-35, "create part");
			{
				// stuff goes here for tab 2
			}
			tab2->end();
		}
		tabs->end();
	}
	
	win->end();
	win->show();
	return(Fl::run());
}
