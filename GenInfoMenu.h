//GenInfoMenu header file

#ifndef GENINFOMENU_H
#define GENINFOMENU_H

//Include statements
#include "Undergrad.h"
#include "Grad.h"
#include <iostream>
#include <gtkmm.h>
#include <string>
using namespace std;

//Define GenInfoMenu class
class GenInfoMenu : public Gtk::Frame 	{
	//Private members
	private:
		class ModelColumns : public Gtk::TreeModel::ColumnRecord	{
			public:
				ModelColumns()	{	add(m_col_value);	}

				Gtk::TreeModelColumn<Glib::ustring> m_col_value;
		};
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
		Gtk::ComboBoxText* researchT;
		Gtk::ComboBoxText* programT;
		Gtk::Entry* supervisorT;
		Gtk::Entry* cgpaT;
		Gtk::Label* firstNameL;
		Gtk::Label* lastNameL;
		Gtk::Label* stuNumL;
		Gtk::Label* majorL;
		Gtk::Label* yearL;
		Gtk::Label* emailL;
		Gtk::Label* gpaL;
		Gtk::Label* cgpaL;
		Gtk::Label* researchL;
		Gtk::Label* programL;
		Gtk::Label* supervisorL;
		ModelColumns research_Columns;
		ModelColumns program_Columns;
		Glib::RefPtr<Gtk::ListStore> research_refTreeModel;
		Glib::RefPtr<Gtk::ListStore> program_refTreeModel;

	//Public members
	public:
		GenInfoMenu(string type);
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
		Gtk::ComboBoxText* getResearch();
		Gtk::ComboBoxText* getProgram();
		Gtk::Entry* getSupervisor();
		void setFirstName(string name);
		void setLastName(string name);
		void setStuNum(string num);
		void setMajor(string major);
		void setYear(string y);
		void setEmail(string r);
		void setGpa(string g);
		void setCgpa(string g);
		void setResearch(string r);
		void setProgram(string p);
		void setSupervisor(string s);
		bool checkInfo(string type);
		void setUndergradInfo(Undergrad*);
		void setGradInfo(Grad*);
};

#endif
