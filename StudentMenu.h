//StudentMenu header file

#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <gtkmm.h>

//Define StudentMenu class
class StudentMenu : public Gtk::Frame	{
	//Private members
	private:
		Gtk::VBox* box;
		Gtk::Button* createB;
		Gtk::Button* editB;
		Gtk::Button* cancelB;
	//Public members
	public:
		StudentMenu();
		~StudentMenu();
		Gtk::Box* getBox();
		Gtk::Button* getCreateButton();
		Gtk::Button* getEditButton();
		Gtk::Button* getCancelButton();
};

#endif
