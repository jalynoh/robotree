//	Jalyn Gilliam
//	1001170694
//	Robotree Project
//
//	Base code from: 1325 Object Oriented Programming - Lecture 19
//	Taught by: Professor George Rice


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>

#include "shop.h"

using namespace std;

//
// Shop class instance
//

Shop shop{"Robbie Robot Shop"};

//
// Declarations
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

void exit_model_reportCB(Fl_Widget* w, void* p);
class Model_Report_Dialog;

void create_customerCB(Fl_Widget* w, void* p);
void cancel_customerCB(Fl_Widget* w, void* p);
class Create_Customer_Dialog;

void create_associateCB(Fl_Widget* w, void* p);
void cancel_associateCB(Fl_Widget* w, void* p);
class Create_Associate_Dialog;

void create_orderCB(Fl_Widget* w, void* p);
void cancel_orderCB(Fl_Widget* w, void* p);
class Create_Order_Dialog;

void exit_order_reportCB(Fl_Widget* w, void* p);
class Order_Report_Dialog;

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
Model_Report_Dialog *model_report_dlg;
Create_Customer_Dialog *create_customer_dlg;
Create_Associate_Dialog *create_associate_dlg;
Create_Order_Dialog *create_order_dlg;
Order_Report_Dialog *order_report_dlg;

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
		dialog = new Fl_Window(340, 540, "Robot Model");
		
		rm_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rm_name->align(FL_ALIGN_LEFT);
		
		rm_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rm_part_number->align(FL_ALIGN_LEFT);
		
		rm_price = new Fl_Input(120, 70, 210, 25, "Price:");
		rm_price->align(FL_ALIGN_LEFT);
		
		rm_arm = new Fl_Browser(120, 100, 210, 75, "Arm:");
		rm_arm->type(FL_MULTI_BROWSER);
		rm_arm->align(FL_ALIGN_LEFT);
		
		rm_battery = new Fl_Browser(120, 180, 210, 75, "Battery:");
		rm_battery->type(FL_MULTI_BROWSER);
		rm_battery->align(FL_ALIGN_LEFT);
		
		rm_head = new Fl_Browser(120, 260, 210, 75, "Head:");
		rm_head->type(FL_HOLD_BROWSER);
		rm_head->align(FL_ALIGN_LEFT);
		
		rm_locomotor = new Fl_Browser(120, 340, 210, 75, "Locomotor:");
		rm_locomotor->type(FL_HOLD_BROWSER);
		rm_locomotor->align(FL_ALIGN_LEFT);
		
		rm_torso = new Fl_Browser(120, 420, 210, 75, "Torso:");
		rm_torso->type(FL_HOLD_BROWSER);
		rm_torso->align(FL_ALIGN_LEFT);
		
		rm_create = new Fl_Return_Button(145, 500, 120, 25, "Create");
		rm_create->callback((Fl_Callback *)create_robot_modelCB, 0);
		
		rm_cancel = new Fl_Button(270, 500, 60, 25, "Cancel");
		rm_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);
		
		dialog->resizable(dialog);
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return rm_name->value();}
	string part_model_number() {return rm_part_number->value();}
	string price() {return rm_price->value();}
	int arm() {return rm_arm->value();}
	int battery() {return rm_battery->value();}
	int head() {return rm_head->value();}
	int locomotor() {return rm_locomotor->value();}
	int torso() {return rm_torso->value();}
	
	
	Fl_Window *dialog;
	Fl_Input *rm_name;
	Fl_Input *rm_part_number;
	Fl_Input *rm_price;
	Fl_Browser *rm_arm;
	Fl_Browser *rm_battery;
	Fl_Browser *rm_head;
	Fl_Browser *rm_locomotor;
	Fl_Browser *rm_torso;
	Fl_Return_Button *rm_create;
	Fl_Button *rm_cancel;
};

//
// Model report dialog
//

class Model_Report_Dialog {
public:
	Model_Report_Dialog() {
		dialog = new Fl_Window(340, 310, "Model Browser");
		
		mr = new Fl_Browser(10, 10, 320, 250);
		mr->type(FL_MULTI_BROWSER);
		mr->align(FL_ALIGN_LEFT);
		
		mr_exit = new Fl_Button(270, 270, 60, 25, "Exit");
		mr_exit->callback((Fl_Callback *)exit_model_reportCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	
	
	Fl_Window *dialog;
	Fl_Browser *mr;
	Fl_Button *mr_exit;
};

//
// Create Customer pop-out dialog box
//

class Create_Customer_Dialog {
public:
	Create_Customer_Dialog() {
		dialog = new Fl_Window(340, 170, "Create Customer");
		
		cc_name = new Fl_Input(120, 10, 210, 25, "Name:");
		cc_name->align(FL_ALIGN_LEFT);
		
		cc_phone = new Fl_Input(120, 40, 210, 25, "Phone:");
		cc_phone->align(FL_ALIGN_LEFT);
		
		cc_address = new Fl_Input(120, 70, 210, 25, "Address:");
		cc_address->align(FL_ALIGN_LEFT);
		
		cc_email = new Fl_Input(120, 100, 210, 25, "Email:");
		cc_email->align(FL_ALIGN_LEFT);

		cc_create = new Fl_Return_Button(145, 130, 120, 25, "Create");
		cc_create->callback((Fl_Callback *)create_customerCB, 0);
		
		cc_cancel = new Fl_Button(270, 130, 60, 25, "Cancel");
		cc_cancel->callback((Fl_Callback *)cancel_customerCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return cc_name->value();}
	string phone() {return cc_phone->value();}
	string address() {return cc_address->value();}
	string email() {return cc_email->value();}
	
private:
	Fl_Window *dialog;
	Fl_Input *cc_name;
	Fl_Input *cc_address;
	Fl_Input *cc_phone;
	Fl_Input *cc_email;
	Fl_Return_Button *cc_create;
	Fl_Button *cc_cancel;
};

//
// Create Sales Associate pop-out dialog box
//

class Create_Associate_Dialog {
public:
	Create_Associate_Dialog() {
		dialog = new Fl_Window(340, 110, "Create Sales Associate");
		
		ca_name = new Fl_Input(120, 10, 210, 25, "Name:");
		ca_name->align(FL_ALIGN_LEFT);
		
		ca_number = new Fl_Input(120, 40, 210, 25, "Number:");
		ca_number->align(FL_ALIGN_LEFT);

		ca_create = new Fl_Return_Button(145, 70, 120, 25, "Create");
		ca_create->callback((Fl_Callback *)create_associateCB, 0);
		
		ca_cancel = new Fl_Button(270, 70, 60, 25, "Cancel");
		ca_cancel->callback((Fl_Callback *)cancel_associateCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string name() {return ca_name->value();}
	string number() {return ca_number->value();}
	
private:
	Fl_Window *dialog;
	Fl_Input *ca_name;
	Fl_Input *ca_number;
	Fl_Return_Button *ca_create;
	Fl_Button *ca_cancel;
};

//
// Create Order pop out dialog
//

class Create_Order_Dialog {
public:
	Create_Order_Dialog() {
		dialog = new Fl_Window(340, 350, "Create Order");
		
		co_number = new Fl_Input(120, 10, 210, 25, "Order Number:");
		co_number->align(FL_ALIGN_LEFT);
		
		co_date = new Fl_Input(120, 40, 210, 25, "Date of Sale:");
		co_date->align(FL_ALIGN_LEFT);
		
		co_model = new Fl_Browser(120, 70, 210, 75, "Model:");
		co_model->type(FL_MULTI_BROWSER);
		co_model->align(FL_ALIGN_LEFT);
		
		co_customer = new Fl_Browser(120, 150, 210, 75, "Customer:");
		co_customer->type(FL_MULTI_BROWSER);
		co_customer->align(FL_ALIGN_LEFT);
		
		co_associate = new Fl_Browser(120, 230, 210, 75, "Sales Associate:");
		co_associate->type(FL_MULTI_BROWSER);
		co_associate->align(FL_ALIGN_LEFT);
		
		co_create = new Fl_Return_Button(145, 310, 120, 25, "Create");
		co_create->callback((Fl_Callback *)create_orderCB, 0);
		
		co_cancel = new Fl_Button(270, 310, 60, 25, "Cancel");
		co_cancel->callback((Fl_Callback *)cancel_orderCB, 0);
		
		dialog->resizable(dialog);
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	string number() {return co_number->value();}
	string date() {return co_date->value();}
	int model() {return co_model->value();}
	int customer() {return co_customer->value();}
	int associate() {return co_associate->value();}
	
	
	Fl_Window *dialog;
	Fl_Input *co_number;
	Fl_Input *co_date;
	Fl_Browser *co_model;
	Fl_Browser *co_customer;
	Fl_Browser *co_associate;
	Fl_Return_Button *co_create;
	Fl_Button *co_cancel;
};

//
// Order report dialog
//

class Order_Report_Dialog {
public:
	Order_Report_Dialog() {
		dialog = new Fl_Window(340, 310, "Order Browser");
		
		ord = new Fl_Browser(10, 10, 320, 250);
		ord->type(FL_MULTI_BROWSER);
		ord->align(FL_ALIGN_LEFT);
		
		ord_exit = new Fl_Button(270, 270, 60, 25, "Exit");
		ord_exit->callback((Fl_Callback *)exit_order_reportCB, 0);
		
		dialog->end();
		dialog->set_non_modal();
	}
	
	void show() {dialog->show();}
	void hide() {dialog->hide();}
	
	
	Fl_Window *dialog;
	Fl_Browser *ord;
	Fl_Button *ord_exit;
};

//
// Callbacks
//


void populate_fieldsCB(Fl_Widget* w, void* p) { // test option that populates fields with parts, customers and associates.
	for(int i; i < 10; i++) {
		shop.create_arm(("Armathon"+(to_string(i))+""), "13566", 123.3, 89.45, 300, "");
		shop.create_head(("Headathon"+(to_string(i))+""), "24324", 66.5, 3242, "");
		shop.create_torso(("Torsoathon"+(to_string(i))+""), "32442", 2344.55, 7465456, 3, "");
		shop.create_battery(("Batterathon"+(to_string(i))+""), "56454", 1234.5, 5784.6, 55.3, "");
		shop.create_locomotor(("Locoathon"+(to_string(i))+""), "85636", 432.3, 567.5, 5342, 9549, "");
		shop.create_sales_associate(("SalesPerson"+(to_string(i))), "6823457689");
		shop.create_customer(("CustomerPerson"+(to_string(i))), "3243324324");
	}
}


// Robot Part Arm callback
//
void menu_create_robot_part_armCB(Fl_Widget* w, void* p) {
	robot_part_arm_dlg->show();
}
void create_robot_part_armCB(Fl_Widget* w, void* p) { // Calls to shop.cpp's create arm
	shop.create_arm(
					robot_part_arm_dlg->name(),
					robot_part_arm_dlg->part_arm_number(),
					stod(robot_part_arm_dlg->weight()),		// Create if statements for the conversions
					stod(robot_part_arm_dlg->cost()),		// Create if statements for the conversions
					stoi(robot_part_arm_dlg->power()),		// Create if statements for the conversions
					robot_part_arm_dlg->description()
					);
	robot_part_arm_dlg->hide();
}
void cancel_robot_part_armCB(Fl_Widget* w, void* p) {
	robot_part_arm_dlg->hide();
}


// Robot Part Battery callback
//
void menu_create_robot_part_batteryCB(Fl_Widget* w, void* p) {
	robot_part_battery_dlg->show();
}
void create_robot_part_batteryCB(Fl_Widget* w, void* p) { // Replace with call to model!
	shop.create_battery(
						robot_part_battery_dlg->name(),
						robot_part_battery_dlg->part_battery_number(),
						stod(robot_part_battery_dlg->weight()),
						stod(robot_part_battery_dlg->cost()),
						stoi(robot_part_battery_dlg->poweramt()),
						robot_part_battery_dlg->description()
						);
	robot_part_battery_dlg->hide();
}
void cancel_robot_part_batteryCB(Fl_Widget* w, void* p) {
	robot_part_battery_dlg->hide();
}


// Robot Part Head callback
//
void menu_create_robot_part_headCB(Fl_Widget* w, void* p) {
	robot_part_head_dlg->show();
}
void create_robot_part_headCB(Fl_Widget* w, void* p) { // Replace with call to model!
	shop.create_head(
					 robot_part_head_dlg->name(),
					 robot_part_head_dlg->part_head_number(),
					 stod(robot_part_head_dlg->weight()),
					 stod(robot_part_head_dlg->cost()),
					 robot_part_head_dlg->description()
					 );
	robot_part_head_dlg->hide();
}
void cancel_robot_part_headCB(Fl_Widget* w, void* p) {
	robot_part_head_dlg->hide();
}


// Robot Part Locomotor callback
//
void menu_create_robot_part_locomotorCB(Fl_Widget* w, void* p) {
	robot_part_locomotor_dlg->show();
}
void create_robot_part_locomotorCB(Fl_Widget* w, void* p) { // Replace with call to model!
	shop.create_locomotor(
						  robot_part_locomotor_dlg->name(),
						  robot_part_locomotor_dlg->part_locomotor_number(),
						  stod(robot_part_locomotor_dlg->weight()),
						  stod(robot_part_locomotor_dlg->cost()),
						  stoi(robot_part_locomotor_dlg->power()),
						  stoi(robot_part_locomotor_dlg->speed()),
						  robot_part_arm_dlg->description()
						  );
	robot_part_locomotor_dlg->hide();
}
void cancel_robot_part_locomotorCB(Fl_Widget* w, void* p) {
	robot_part_locomotor_dlg->hide();
}


// Robot Part Torso callback
//
void menu_create_robot_part_torsoCB(Fl_Widget* w, void* p) {
	robot_part_torso_dlg->show();
}
void create_robot_part_torsoCB(Fl_Widget* w, void* p) { // Replace with call to model!
	shop.create_torso(
					  robot_part_torso_dlg->name(),
					  robot_part_torso_dlg->part_torso_number(),
					  stod(robot_part_torso_dlg->weight()),
					  stod(robot_part_torso_dlg->cost()),
					  stoi(robot_part_torso_dlg->batterycap()),
					  robot_part_torso_dlg->description()
					  );
	robot_part_torso_dlg->hide();
}
void cancel_robot_part_torsoCB(Fl_Widget* w, void* p) {
	robot_part_torso_dlg->hide();
}


// Robot Model callback
//
void menu_create_robot_modelCB(Fl_Widget* w, void* p) { //For loop for each of the browser arrays
	
	robot_model_dlg->rm_arm->clear();
	robot_model_dlg->rm_head->clear();
	robot_model_dlg->rm_battery->clear();
	robot_model_dlg->rm_locomotor->clear();
	robot_model_dlg->rm_torso->clear();
	
	for(int i = 0; i < shop.arms().size(); ++i) { // Arm browser population
		string arm_string;
		arm_string += shop.arms()[i].name()
						+ ", "
						+ shop.arms()[i].part_number()
						+ ", "
						+ to_string(shop.arms()[i].weight())
						+ "lbs, $"
						+ to_string(shop.arms()[i].cost());
		
		robot_model_dlg->rm_arm->add(arm_string.c_str());
	}
	
	for(int i = 0; i < shop.batteries().size(); ++i) { // Battery browser population
		string battery_string;
		battery_string += shop.batteries()[i].name()
						+ ", "
						+ shop.batteries()[i].part_number()
						+ ", "
						+ to_string(shop.batteries()[i].weight())
						+ "lbs, $"
						+ to_string(shop.batteries()[i].cost());
		robot_model_dlg->rm_battery->add(battery_string.c_str());
	}
	
	for(int i = 0; i < shop.heads().size(); ++i) { // Head browser population
		string head_string;
		head_string += shop.heads()[i].name()
						+ ", "
						+ shop.heads()[i].part_number()
						+ ", "
						+ to_string(shop.heads()[i].weight())
						+ "lbs, $"
						+ to_string(shop.heads()[i].cost());
		robot_model_dlg->rm_head->add(head_string.c_str());
	}
	
	for(int i = 0; i < shop.locomotors().size(); ++i) { // Locomotor browser population
		string locomotor_string;
		locomotor_string += shop.locomotors()[i].name()
						+ ", "
						+ shop.locomotors()[i].part_number()
						+ ", "
						+ to_string(shop.locomotors()[i].weight())
						+ "lbs, $"
						+ to_string(shop.locomotors()[i].cost());
		robot_model_dlg->rm_locomotor->add(locomotor_string.c_str());
	}
	
	for(int i = 0; i < shop.torsos().size(); ++i) { // Torso browser population
		string torso_string;
		torso_string += shop.torsos()[i].name()
						+ ", "
						+ shop.torsos()[i].part_number()
						+ ", "
						+ to_string(shop.torsos()[i].weight())
						+ "lbs, $"
						+ to_string(shop.torsos()[i].cost());
		robot_model_dlg->rm_torso->add(torso_string.c_str());
	}
	
	robot_model_dlg->show();
}

void create_robot_modelCB(Fl_Widget* w, void* p) {
	shop.create_model(
					  robot_model_dlg->name(),
					  robot_model_dlg->part_model_number(),
					  stod(robot_model_dlg->price()),
					  shop.torsos()[robot_model_dlg->torso()],
					  shop.heads()[robot_model_dlg->head()],
					  shop.arms()[robot_model_dlg->arm()],
					  shop.arms()[robot_model_dlg->arm()],
					  shop.locomotors()[robot_model_dlg->locomotor()],
					  shop.batteries()[robot_model_dlg->battery()],
					  shop.batteries()[robot_model_dlg->battery()],
					  shop.batteries()[robot_model_dlg->battery()]
					);
	
	robot_model_dlg->hide();
}

void cancel_robot_modelCB(Fl_Widget* w, void* p) {
	robot_model_dlg->hide();
}


// Model report callback
//
void menu_model_reportCB(Fl_Widget* w, void* p) {
	model_report_dlg->mr->clear();
	for (int i = 0; i < shop.models().size(); ++i) {
		string model_string;
		model_string += shop.models()[i].name()
						+ ", "
						+ shop.models()[i].part_number()
						+ ", $"
						+ to_string(shop.models()[i].price());
		
		
		model_report_dlg->mr->add(model_string.c_str());
	}
	
	
	
	model_report_dlg->show();
}
void exit_model_reportCB(Fl_Widget* w, void* p) {
	model_report_dlg->hide();
}


// Create Customer callback
//
void menu_create_customerCB(Fl_Widget* w, void* p) {
	create_customer_dlg->show();
}
void create_customerCB(Fl_Widget* w, void* p) { // Calls to shop.cpp's create customer
	shop.create_customer(
					create_customer_dlg->name(),
					create_customer_dlg->phone()
					);
	create_customer_dlg->hide();
}
void cancel_customerCB(Fl_Widget* w, void* p) {
	create_customer_dlg->hide();
}


// Create Customer callback
//
void menu_create_associateCB(Fl_Widget* w, void* p) {
	create_associate_dlg->show();
}
void create_associateCB(Fl_Widget* w, void* p) { // Calls to shop.cpp's create sales associate
	shop.create_sales_associate(
						 create_associate_dlg->name(),
						 create_associate_dlg->number()
						 );
	create_associate_dlg->hide();
}
void cancel_associateCB(Fl_Widget* w, void* p) {
	create_associate_dlg->hide();
}


// Robot Model callback
//
void menu_create_orderCB(Fl_Widget* w, void* p) { //For loop for each of the browser arrays
	
	create_order_dlg->co_model->clear();
	create_order_dlg->co_customer->clear();
	create_order_dlg->co_associate->clear();
	
	for(int i = 0; i < shop.models().size(); ++i) { // Model browser population
		string model_string;
		model_string += shop.models()[i].name()
						+ ", $"
						+ to_string(shop.models()[i].price());

		create_order_dlg->co_model->add(model_string.c_str());
	}
	
	for(int i = 0; i < shop.customers().size(); ++i) { // Customers browser population
		string customer_string;
		customer_string += shop.customers()[i].name()
						+ ", "
						+ shop.customers()[i].customer_number();
		
		create_order_dlg->co_customer->add(customer_string.c_str());
	}
	
	for(int i = 0; i < shop.sales_associates().size(); ++i) { // Sales Associates browser population
		string associates_string;
		associates_string += shop.sales_associates()[i].name()
						+ ", "
						+ shop.sales_associates()[i].employee_number();
		
		create_order_dlg->co_associate->add(associates_string.c_str());
	}
	
	create_order_dlg->show();
}

void create_orderCB(Fl_Widget* w, void* p) {
	shop.create_order(
					  create_order_dlg->number(),
					  create_order_dlg->date(),
					  shop.models()[create_order_dlg->model()],
					  shop.customers()[create_order_dlg->customer()],
					  shop.sales_associates()[create_order_dlg->associate()]
					  );
	
	create_order_dlg->hide();
}

void cancel_orderCB(Fl_Widget* w, void* p) {
	create_order_dlg->hide();
}


// Order report callback
//
void menu_order_reportCB(Fl_Widget* w, void* p) {
	order_report_dlg->ord->clear();
	for (int i = 0; i < shop.orders().size(); ++i) {
		string order_string;
		order_string += shop.orders()[i].order_number()
					+ ", "
					+ shop.orders()[i].date_of_sale();
		
		order_report_dlg->ord->add(order_string.c_str());
	}
	
	
	
	order_report_dlg->show();
}
void exit_order_reportCB(Fl_Widget* w, void* p) {
	order_report_dlg->hide();
}


// Close callback
//
void closeCB(Fl_Widget* w, void* p) {
	win->hide();
}

//
// Menu
//

Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
		{ "&Populate Fields", FL_ALT + 'n', (Fl_Callback *)populate_fieldsCB },
		{ "&Quit", FL_ALT + 'q', (Fl_Callback *)closeCB },
		{ 0 },
	{ "&Create", 0, 0, 0, FL_SUBMENU },
		{ "Order", 0, (Fl_Callback *)menu_create_orderCB, 0, FL_MENU_DIVIDER  },
		{ "Customer", 0, (Fl_Callback *)menu_create_customerCB },
		{ "Sales Associate", 0, (Fl_Callback *)menu_create_associateCB, 0, FL_MENU_DIVIDER  },
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
		{ "All Orders", 0, (Fl_Callback *)menu_order_reportCB },
		{ "All Robot Models", 0, (Fl_Callback *)menu_model_reportCB },
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
	model_report_dlg = new Model_Report_Dialog();
	create_customer_dlg = new Create_Customer_Dialog();
	create_associate_dlg = new Create_Associate_Dialog();
	create_order_dlg = new Create_Order_Dialog();
	order_report_dlg = new Order_Report_Dialog();
	
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
