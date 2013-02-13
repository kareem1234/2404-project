//RelatedCourseMenu header file

#ifndef RELATEDCOURSEMENU_H
#define RELATEDCOURSEMENU_H

#include <gtkmm.h>
#include <string>
using namespace std;

//Define RelatedCourseMenu class
class RelatedCourseMenu : public Gtk::Frame 	{
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
		Gtk::ComboBoxText* finalD;
		Gtk::Label* termL;
		Gtk::Label* yearL;
		Gtk::Label* finalL;
		ModelColumns term_Columns;
		ModelColumns grade_Columns;
		Glib::RefPtr<Gtk::ListStore> term_refTreeModel;
		Glib::RefPtr<Gtk::ListStore> grade_refTreeModel;

	//Public data members
	public:
		RelatedCourseMenu();
		~RelatedCourseMenu();
		Gtk::Grid* getGrid();
		Gtk::Button* getAddButton();
		Gtk::Button* getNextButton();
		Gtk::ComboBoxText* getTerm();
		Gtk::Entry* getYear();
		Gtk::ComboBoxText* getFinalGrade();
		void setYear(string);
		bool checkInput();
};

#endif
