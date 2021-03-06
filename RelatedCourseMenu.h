//RelatedCourseMenu header file

#ifndef RELATEDCOURSEMENU_H
#define RELATEDCOURSEMENU_H

#include <gtkmm.h>
#include <string>
using namespace std;
#include "Application.h"
#include "RelatedCourse.h"

//Define RelatedCourseMenu class
class RelatedCourseMenu : public Gtk::Frame 	{
	//Private data members
	private:
		
		class ModelColumns : public Gtk::TreeModel::ColumnRecord	{
			public:
				ModelColumns()	{	add(m_col_value);	}

				Gtk::TreeModelColumn<Glib::ustring> m_col_value;
		};
		int type;
		Gtk::Grid* grid;
		Gtk::Button* addCourseB;
		Gtk::Button* nextB;
		Gtk::Label* relatedCourseL;
		Gtk::ComboBoxText* termD;
		Gtk::Entry* yearT;
		Gtk::ComboBoxText* finalD;
		Gtk::Button* deleteB;
		Gtk::Label* termL;
		Gtk::Label* yearL;
		Gtk::Label* finalL;
		ModelColumns term_Columns;
		ModelColumns grade_Columns;
		Glib::RefPtr<Gtk::ListStore> term_refTreeModel;
		Glib::RefPtr<Gtk::ListStore> grade_refTreeModel;

	//Public data members
	public:
		RelatedCourseMenu(int t);
		~RelatedCourseMenu();
		int getType();
		Gtk::Grid* getGrid();
		Gtk::Button* getAddButton();
		Gtk::Button* getNextButton();
		Gtk::Button* getDeleteButton();
		Gtk::ComboBoxText* getTerm();
		Gtk::Entry* getYear();
		Gtk::ComboBoxText* getFinalGrade();
		void setYear(string);
		void loadCourse(RelatedCourse&);
		bool checkInput();
		void loadCourse(RelatedCourse*);
		void applyRelatedCourse(Application&);
};

#endif
