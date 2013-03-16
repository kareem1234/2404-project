//VerificationMenu header file

#ifndef VERIFICATIONMENU_H
#define VERIFICATIONMENU_H

//Include statements
#include <gtkmm.h>

class VerificationMenu : public Gtk::Frame	{
	//Private data members
	private:
		Gtk::VBox* box;
		Gtk::Label* numL;
		Gtk::Entry* numT;
		Gtk::Button* submit;

	//Public data members
	public:
		VerificationMenu();
		~VerificationMenu();
		Gtk::VBox* getBox();
		Gtk::Entry* getNumber();
		Gtk::Button* getSubmit();
		bool checkInput();
};

#endif
