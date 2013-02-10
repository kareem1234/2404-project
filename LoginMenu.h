//LoginMenu header file

#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <gtkmm.h> 

//Define LoginMenu class
class LoginMenu	: public Gtk::Frame {
	//Private members
	private:
		Gtk::VBox*  box;
		Gtk::Button* studentB;
		Gtk::Button* teacherB;
	//Public members
	public:
		LoginMenu();
		~LoginMenu();
		Gtk::VBox* getBox();
		Gtk::Button* getStudentButton();
		Gtk::Button* getTeacherButton();
};

#endif
