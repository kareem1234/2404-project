//TACourseMenu header file

#ifndef TACOURSEMENU_H
#define TACOURSEMENU_H

#include <gtkmm.h>
#include <string>
using namespace std;
#include "Undergrad.h"
#include "Grad.h"

//Define TACourseMenu class
class TACourseMenu : public Gtk::Frame 	{
	//Private data members
	private:
		
		class ModelColumns : public Gtk::TreeModel::ColumnRecord	{
		public:
			ModelColumns()	{	add(m_col_value);	}

			Gtk::TreeModelColumn<Glib::ustring> m_col_value;
		};

		Gtk::Grid* grid;
		Gtk::Button* addCourseB;
		Gtk::Button* nextB;
		Gtk::Label* relatedCourseL;
		Gtk::ComboBoxText* termD;
		Gtk::Entry* yearT;
		Gtk::Entry* supervisorT;
		Gtk::Label* termL;
		Gtk::Label* yearL;
		Gtk::Label* supervisorL;
		ModelColumns term_Columns;
		Glib::RefPtr<Gtk::ListStore> term_refTreeModel;

	//Public data members
	public:
		TACourseMenu();
		~TACourseMenu();
		Gtk::Grid* getGrid();
		Gtk::Button* getAddButton();
		Gtk::Button* getNextButton();
		Gtk::ComboBoxText* getTerm();
		Gtk::Entry* getYear();
		Gtk::Entry* getSupervisor();
		void setYear(string);
		void setSupervisor(string);
		int checkInput();
		void applyUnderTACourse(Undergrad*);
		void applyGradTACourse(Grad*);
};

#endif
