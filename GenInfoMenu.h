//GenInfoMenu header file

#ifndef GENINFOMENU_H
#define GENINFOMENU_H

//Include statements
#include "Student.h"
#include <iostream>
#include <gtkmm.h>
#include <string>
using namespace std;

//Define GenInfoMenu class
class GenInfoMenu : public Gtk::Frame 	{
	//Private members
	private:
		Gtk::Grid* grid;
		Gtk::Button* nextB;
		Gtk::Label* genInfoL;
		Gtk::Entry* firstNameT;
		Gtk::Entry* lastNameT;
		Gtk::Entry* stuNumT;
		Gtk::Entry* majorT;
		Gtk::Entry* yearT;
		Gtk::Entry* emailT;
		Gtk::Entry* gpaT;
		Gtk::Entry* cgpaT;
		Gtk::Label* firstNameL;
		Gtk::Label* lastNameL;
		Gtk::Label* stuNumL;
		Gtk::Label* majorL;
		Gtk::Label* yearL;
		Gtk::Label* emailL;
		Gtk::Label* gpaL;
		Gtk::Label* cgpaL;
	//Public members
	public:
		GenInfoMenu();
		~GenInfoMenu();
		Gtk::Grid* getGrid();
		Gtk::Button* getNext();
		Gtk::Entry* getFirstName();
		Gtk::Entry* getLastName();
		Gtk::Entry* getStuNum();
		Gtk::Entry* getMajor();
		Gtk::Entry* getYear();
		Gtk::Entry* getEmail();
		Gtk::Entry* getGpa();
		Gtk::Entry* getCgpa();
		void setFirstName(string name);
		void setLastName(string name);
		void setStuNum(string num);
		void setMajor(string major);
		void setYear(string y);
		void setEmail(string r);
		void setGpa(string g);
		void setCgpa(string g);
		bool checkInfo();
		void setStudentInfo(Student*);
};

#endif
