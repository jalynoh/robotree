// Professor George Rice: OOP
// Lecture 19
///usr/local/Cellar/fltk/1.3.3/include/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>

//#include "shop.h"

using namespace std;

//
// Class instance
//

//Shop shop{"Robbie Robot Shop"};

//
// Declarations (we'll define later, just need to declare some variables!)
//

void create_robot_part_armCB(Fl_Widget* w, void* p);
void cancel_robot_part_armCB(Fl_Widget* w, void* p);
class Robot_Part_Arm_Dialog;

void create_robot_part_batteryCB(Fl_Widget* w, void* p);
void cancel_robot_part_batteryCB(Fl_Widget* w, void* p);
class Robot_Part_Battery_Dialog;

void create_robot_part_headCB(Fl_Widget* w, void* p);
void cancel_robot_part_headCB(Fl_Widget* w, void* p);
class Robot_Part_Head_Dialog;

void create_robot_part_locomotorCB(Fl_Widget* w, void* p);
void cancel_robot_part_locomotorCB(Fl_Widget* w, void* p);
class Robot_Part_Locomotor_Dialog;

void create_robot_part_torsoCB(Fl_Widget* w, void* p);
void cancel_robot_part_torsoCB(Fl_Widget* w, void* p);
class Robot_Part_Torso_Dialog;

void create_robot_modelCB(Fl_Widget* w, void* p);
void cancel_robot_modelCB(Fl_Widget* w, void* p);
class Robot_Model_Dialog;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Arm_Dialog *robot_part_arm_dlg;
Robot_Part_Battery_Dialog *robot_part_battery_dlg;
Robot_Part_Head_Dialog *robot_part_head_dlg;
Robot_Part_Locomotor_Dialog *robot_part_locomotor_dlg;
Robot_Part_Torso_Dialog *robot_part_torso_dlg;

Robot_Model_Dialog *robot_model_dlg;

//
// Robot Part Arm pop-out dialog box
//

class Robot_Part_Arm_Dialog {
	public:
	Robot_Part_Arm_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Arm");
		
		rpa_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rpa_name->align(FL_ALIGN_LEFT);
		
		rpa_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rpa_part_number->align(FL_ALIGN_LEFT);
		
		rpa_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rpa_weight->align(FL_ALIGN_LEFT);
		
		rpa_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rpa_cost->align(FL_ALIGN_LEFT);
		
		rpa_power = new Fl_Input(120, 130, 210, 25, "Power:");
		rpa_power->align(FL_ALIGN_LEFT);
		
		rpa_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rpa_description->align(FL_ALIGN_LEFT);
		
		rpa_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rpa_create->callback((Fl_Callback *)create_robot_part_armCB, 0);
		
		rpa_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rpa_cancel->callback((Fl_Callback *)cancel_robot_part_armCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rpa_name->value();}
	string part_arm_number() {return rpa_part_number->value();}
	string weight() {return rpa_weight->value();}
	string cost() {return rpa_cost->value();}
	string power() {return rpa_power->value();}
	string description() {return rpa_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rpa_name;
	Fl_Input *rpa_part_number;
	Fl_Input *rpa_weight;
	Fl_Input *rpa_cost;
	Fl_Input *rpa_power;
	Fl_Input *rpa_description;
	Fl_Return_Button *rpa_create;
	Fl_Button *rpa_cancel;
};

//
// Robot Part Battery pop-out dialog box
//

class Robot_Part_Battery_Dialog {
	public:
	Robot_Part_Battery_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Battery");
		
		rpb_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rpb_name->align(FL_ALIGN_LEFT);
		
		rpb_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rpb_part_number->align(FL_ALIGN_LEFT);
		
		rpb_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rpb_weight->align(FL_ALIGN_LEFT);
		
		rpb_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rpb_cost->align(FL_ALIGN_LEFT);
		
		rpb_poweramt = new Fl_Input(120, 130, 210, 25, "Power Amt:");
		rpb_poweramt->align(FL_ALIGN_LEFT);
		
		rpb_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rpb_description->align(FL_ALIGN_LEFT);
		
		rpb_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rpb_create->callback((Fl_Callback *)create_robot_part_batteryCB, 0);
		
		rpb_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rpb_cancel->callback((Fl_Callback *)cancel_robot_part_batteryCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rpb_name->value();}
	string part_battery_number() {return rpb_part_number->value();}
	string weight() {return rpb_weight->value();}
	string cost() {return rpb_cost->value();}
	string poweramt() {return rpb_poweramt->value();}
	string description() {return rpb_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rpb_name;
	Fl_Input *rpb_part_number;
	Fl_Input *rpb_weight;
	Fl_Input *rpb_cost;
	Fl_Input *rpb_poweramt;
	Fl_Input *rpb_description;
	Fl_Return_Button *rpb_create;
	Fl_Button *rpb_cancel;
};

//
// Robot Part Head pop-out dialog box
//

class Robot_Part_Head_Dialog {
	public:
	Robot_Part_Head_Dialog() {
		dialog = new Fl_Window(340, 240, "Robot Head");
		
		rph_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rph_name->align(FL_ALIGN_LEFT);
		
		rph_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rph_part_number->align(FL_ALIGN_LEFT);
		
		rph_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rph_weight->align(FL_ALIGN_LEFT);
		
		rph_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rph_cost->align(FL_ALIGN_LEFT);
		
		rph_description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rph_description->align(FL_ALIGN_LEFT);
		
		rph_create = new Fl_Return_Button(145, 210, 120, 25, "Create");
		rph_create->callback((Fl_Callback *)create_robot_part_headCB, 0);
		
		rph_cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
		rph_cancel->callback((Fl_Callback *)cancel_robot_part_headCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rph_name->value();}
	string part_head_number() {return rph_part_number->value();}
	string weight() {return rph_weight->value();}
	string cost() {return rph_cost->value();}
	string description() {return rph_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rph_name;
	Fl_Input *rph_part_number;
	Fl_Input *rph_weight;
	Fl_Input *rph_cost;
	Fl_Input *rph_description;
	Fl_Return_Button *rph_create;
	Fl_Button *rph_cancel;
};

//
// Robot Part Locomotor pop-out dialog box
//

class Robot_Part_Locomotor_Dialog {
	public:
	Robot_Part_Locomotor_Dialog() {
		dialog = new Fl_Window(340, 300, "Robot Locomotor");
		
		rpl_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rpl_name->align(FL_ALIGN_LEFT);
		
		rpl_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rpl_part_number->align(FL_ALIGN_LEFT);
		
		rpl_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rpl_weight->align(FL_ALIGN_LEFT);
		
		rpl_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rpl_cost->align(FL_ALIGN_LEFT);
		
		rpl_power = new Fl_Input(120, 130, 210, 25, "Power:");
		rpl_power->align(FL_ALIGN_LEFT);
		
		rpl_speed = new Fl_Input(120, 160, 210, 25, "Speed:");
		rpl_speed->align(FL_ALIGN_LEFT);
		
		rpl_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
		rpl_description->align(FL_ALIGN_LEFT);
		
		rpl_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
		rpl_create->callback((Fl_Callback *)create_robot_part_locomotorCB, 0);
		
		rpl_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
		rpl_cancel->callback((Fl_Callback *)cancel_robot_part_locomotorCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rpl_name->value();}
	string part_locomotor_number() {return rpl_part_number->value();}
	string weight() {return rpl_weight->value();}
	string cost() {return rpl_cost->value();}
	string power() {return rpl_power->value();}
	string speed() {return rpl_speed->value();}
	string description() {return rpl_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rpl_name;
	Fl_Input *rpl_part_number;
	Fl_Input *rpl_weight;
	Fl_Input *rpl_cost;
	Fl_Input *rpl_power;
	Fl_Input *rpl_speed;
	Fl_Input *rpl_description;
	Fl_Return_Button *rpl_create;
	Fl_Button *rpl_cancel;
};

//
// Robot Part Torso pop-out dialog box
//

class Robot_Part_Torso_Dialog {
	public:
	Robot_Part_Torso_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Torso");
		
		rpt_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rpt_name->align(FL_ALIGN_LEFT);
		
		rpt_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rpt_part_number->align(FL_ALIGN_LEFT);
		
		rpt_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rpt_weight->align(FL_ALIGN_LEFT);
		
		rpt_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rpt_cost->align(FL_ALIGN_LEFT);
		
		rpt_batterycap = new Fl_Input(120, 130, 210, 25, "Battery Cap:");
		rpt_batterycap->align(FL_ALIGN_LEFT);
		
		rpt_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rpt_description->align(FL_ALIGN_LEFT);
		
		rpt_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rpt_create->callback((Fl_Callback *)create_robot_part_torsoCB, 0);
		
		rpt_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rpt_cancel->callback((Fl_Callback *)cancel_robot_part_torsoCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rpt_name->value();}
	string part_torso_number() {return rpt_part_number->value();}
	string weight() {return rpt_weight->value();}
	string cost() {return rpt_cost->value();}
	string batterycap() {return rpt_batterycap->value();}
	string description() {return rpt_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rpt_name;
	Fl_Input *rpt_part_number;
	Fl_Input *rpt_weight;
	Fl_Input *rpt_cost;
	Fl_Input *rpt_batterycap;
	Fl_Input *rpt_description;
	Fl_Return_Button *rpt_create;
	Fl_Button *rpt_cancel;
};

//
// Robot Model pop out dialog
//

class Robot_Model_Dialog {
	public:
	Robot_Model_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Model");
		
		rm_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rm_name->align(FL_ALIGN_LEFT);
		
		rm_part_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
		rm_part_number->align(FL_ALIGN_LEFT);
		
		rm_type = new Fl_Input(120, 70, 210, 25, "Type:");
		rm_type->align(FL_ALIGN_LEFT);
		
		rm_weight = new Fl_Input(120, 100, 210, 25, "Price:");
		rm_weight->align(FL_ALIGN_LEFT);
		
		rm_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		rm_cost->align(FL_ALIGN_LEFT);
		
		rm_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rm_description->align(FL_ALIGN_LEFT);
		
		rm_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rm_create->callback((Fl_Callback *)create_robot_modelCB, 0);
		
		rm_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rm_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rm_name->value();}
	string part_number() {return rm_part_number->value();}
	string type() {return rm_type->value();}
	string weight() {return rm_weight->value();}
	string cost() {return rm_cost->value();}
	string description() {return rm_description->value();}
	
	private:
	Fl_Window *dialog;
	Fl_Input *rm_name;
	Fl_Input *rm_part_number;
	Fl_Input *rm_type;
	Fl_Input *rm_weight;
	Fl_Input *rm_cost;
	Fl_Input *rm_description;
	Fl_Return_Button *rm_create;
	Fl_Button *rm_cancel;
};

//
// Callbacks
//

void CB(Fl_Widget* w, void* p) { } // No action

// Robot Part Arm callback
void menu_create_robot_part_armCB(Fl_Widget* w, void* p) {
	robot_part_arm_dlg->show();
}

void create_robot_part_armCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot arm" << endl;
	cout << "Name    : " << robot_part_arm_dlg->name() << endl;
	cout << "Part #  : " << robot_part_arm_dlg->part_arm_number() << endl;
	cout << "Weight  : " << robot_part_arm_dlg->weight() << endl;
	cout << "Cost    : " << robot_part_arm_dlg->cost() << endl;
	cout << "Power   : " << robot_part_arm_dlg->power() << endl;
	cout << "Descript: " << robot_part_arm_dlg->description() << endl;
	//shop.create_arm("Basic Arm", "276", 1.15, 215.11, 500, "A basic robot arm");
	robot_part_arm_dlg->hide();
}

void cancel_robot_part_armCB(Fl_Widget* w, void* p) {
	robot_part_arm_dlg->hide();
}

// Robot Part Battery callback
void menu_create_robot_part_batteryCB(Fl_Widget* w, void* p) {
	robot_part_battery_dlg->show();
}

void create_robot_part_batteryCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot part" << endl;
	cout << "Name    : " << robot_part_battery_dlg->name() << endl;
	cout << "Part #  : " << robot_part_battery_dlg->part_battery_number() << endl;
	cout << "Weight  : " << robot_part_battery_dlg->weight() << endl;
	cout << "Cost    : " << robot_part_battery_dlg->cost() << endl;
	cout << "PowerAmt: " << robot_part_battery_dlg->poweramt() << endl;
	cout << "Descript: " << robot_part_battery_dlg->description() << endl;
	robot_part_battery_dlg->hide();
}

void cancel_robot_part_batteryCB(Fl_Widget* w, void* p) {
	robot_part_battery_dlg->hide();
}

// Robot Part Head callback
void menu_create_robot_part_headCB(Fl_Widget* w, void* p) {
	robot_part_head_dlg->show();
}

void create_robot_part_headCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot part" << endl;
	cout << "Name    : " << robot_part_head_dlg->name() << endl;
	cout << "Part #  : " << robot_part_head_dlg->part_head_number() << endl;
	cout << "Weight  : " << robot_part_head_dlg->weight() << endl;
	cout << "Cost    : " << robot_part_head_dlg->cost() << endl;
	cout << "Descript: " << robot_part_head_dlg->description() << endl;
	robot_part_head_dlg->hide();
}

void cancel_robot_part_headCB(Fl_Widget* w, void* p) {
	robot_part_head_dlg->hide();
}

// Robot Part Locomotor callback
void menu_create_robot_part_locomotorCB(Fl_Widget* w, void* p) {
	robot_part_locomotor_dlg->show();
}

void create_robot_part_locomotorCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot part" << endl;
	cout << "Name    : " << robot_part_locomotor_dlg->name() << endl;
	cout << "Part #  : " << robot_part_locomotor_dlg->part_locomotor_number() << endl;
	cout << "Weight  : " << robot_part_locomotor_dlg->weight() << endl;
	cout << "Cost    : " << robot_part_locomotor_dlg->cost() << endl;
	cout << "Power   : " << robot_part_locomotor_dlg->power() << endl;
	cout << "Speed   : " << robot_part_locomotor_dlg->speed() << endl;
	cout << "Descript: " << robot_part_locomotor_dlg->description() << endl;
	robot_part_locomotor_dlg->hide();
}

void cancel_robot_part_locomotorCB(Fl_Widget* w, void* p) {
	robot_part_locomotor_dlg->hide();
}

// Robot Part Torso callback
void menu_create_robot_part_torsoCB(Fl_Widget* w, void* p) {
	robot_part_torso_dlg->show();
}

void create_robot_part_torsoCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot part" << endl;
	cout << "Name    : " << robot_part_torso_dlg->name() << endl;
	cout << "Part #  : " << robot_part_torso_dlg->part_torso_number() << endl;
	cout << "Weight  : " << robot_part_torso_dlg->weight() << endl;
	cout << "Cost    : " << robot_part_torso_dlg->cost() << endl;
	cout << "Battery#: " << robot_part_torso_dlg->batterycap() << endl;
	cout << "Descript: " << robot_part_torso_dlg->description() << endl;
	robot_part_torso_dlg->hide();
}

void cancel_robot_part_torsoCB(Fl_Widget* w, void* p) {
	robot_part_torso_dlg->hide();
}

// Robot Model callback
void menu_create_robot_modelCB(Fl_Widget* w, void* p) {
	robot_model_dlg->show();
}

void create_robot_modelCB(Fl_Widget* w, void* p) { // Replace
	cout << "### Creating robot model" << endl;
	cout << "Name    : " << robot_model_dlg->name() << endl;
	cout << "Part #  : " << robot_model_dlg->part_number() << endl;
	cout << "Type    : " << robot_model_dlg->type() << endl;
	cout << "Weight  : " << robot_model_dlg->weight() << endl;
	cout << "Cost    : " << robot_model_dlg->cost() << endl;
	cout << "Descript: " << robot_model_dlg->description() << endl;
	robot_model_dlg->hide();
}

void cancel_robot_modelCB(Fl_Widget* w, void* p) {
	robot_model_dlg->hide();
}


//
// Menu
//

Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
		{ "&New", FL_ALT + 'n', (Fl_Callback *)CB },
		{ "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
		{ "&Save", FL_ALT + 's', (Fl_Callback *)CB },
		{ "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
		{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
		{ 0 },
	{ "&Edit", 0, 0, 0, FL_SUBMENU },
		{ "&Undo", 0, (Fl_Callback *)CB },
		{ "Cu&t", 0, (Fl_Callback *)CB },
		{ "&Copy", 0, (Fl_Callback *)CB },
		{ "&Paste", 0, (Fl_Callback *)CB },
		{ 0 },
	{ "&Create", 0, 0, 0, FL_SUBMENU },
		{ "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
		{ "Customer", 0, (Fl_Callback *)CB },
		{ "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
		{ "Robot Part", 0, 0, 0, FL_SUBMENU },
			{ "Arm", 0, (Fl_Callback *)menu_create_robot_part_armCB },
			{ "Battery", 0, (Fl_Callback *)menu_create_robot_part_batteryCB },
			{ "Head", 0, (Fl_Callback *)menu_create_robot_part_headCB },
			{ "Locomotor", 0, (Fl_Callback *)menu_create_robot_part_locomotorCB },
			{ "Torso", 0, (Fl_Callback *)menu_create_robot_part_torsoCB },
			{ 0 },
		{ "Robot Model", 0, (Fl_Callback *)menu_create_robot_modelCB },
		{ 0 },
	{ "&Report", 0, 0, 0, FL_SUBMENU },
		{ "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
		{ "All Orders", 0, (Fl_Callback *)CB },
		{ "Orders by Customer", 0, (Fl_Callback *)CB },
		{ "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
		{ "All Customers", 0, (Fl_Callback *)CB },
		{ "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
		{ "All Robot Models", 0, (Fl_Callback *)CB },
		{ "All Robot Parts", 0, (Fl_Callback *)CB },
		{ 0 },
	{ "&Help", 0, 0, 0, FL_SUBMENU },
		{ "&Manual", 0, (Fl_Callback *)CB},
		{ "&About", 0, (Fl_Callback *)CB},
		{ 0 },
	{ 0 }
};

//
// Main
//

int main() {
	const int X = 360;
	const int Y = 220;
	
	// Create dialogs
	robot_part_arm_dlg = new Robot_Part_Arm_Dialog();
	robot_part_battery_dlg = new Robot_Part_Battery_Dialog();
	robot_part_head_dlg = new Robot_Part_Head_Dialog();
	robot_part_locomotor_dlg = new Robot_Part_Locomotor_Dialog();
	robot_part_torso_dlg = new Robot_Part_Torso_Dialog();
	
	robot_model_dlg = new Robot_Model_Dialog();
	
	// Create a window
	win = new Fl_Window(X, Y, "Robbie Robot Shop Manager");
	win->color(FL_WHITE);
	
	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);
	
	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}
