//StudentTypeMenu header file

#ifndef STUDENTTYPEMENU_H
#define STUDENTTYPEMENU_H

//Include statements
#include <gtkmm.h>

class StudentTypeMenu : public Gtk::Frame	{
	//Private data members
	private:
		Gtk::VBox* box;
		Gtk::Button* undergrad;
		Gtk::Button* grad;
	//Public data members
	public:
		StudentTypeMenu();
		~StudentTypeMenu();
		Gtk::VBox* getBox();
		Gtk::Button* getUndergrad();
		Gtk::Button* getGrad();
};

#endif
