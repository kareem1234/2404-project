// TeacherMenu header file

#ifndef TEACHERMENU_H
#define TEACHERMENU_H

#include <gtkmm.h>

//Define StudentMenu class
class TeacherMenu: public Gtk::Frame	{
	//Private members
	private:
		Gtk::VBox* box;
		Gtk::Button* viewApp;
		Gtk::Button* all;
		Gtk::Button* viewSummary;
		Gtk::Button* viewAssigned;
		Gtk::Button* editTa;
		Gtk::Button* cancelB;
	//Public members
	public:
		TeacherMenu();
		~TeacherMenu();
		Gtk::VBox* getBox();
		Gtk::Button* getAppButton();
		Gtk::Button* getSummaryButton();
		Gtk::Button* getAssignedButton();
		Gtk::Button* getEditButton();
		Gtk::Button* getCancelButton();
		Gtk::Button* getAllButton();
};

#endif
