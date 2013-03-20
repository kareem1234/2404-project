//CourseList header file

#ifndef COURSELIST_H
#define COURSELIST_H

//Include statements
#include <gtkmm.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "Student.h"
#include "Application.h"


//Define CourseList class
class CourseListMenu : public Gtk::Frame {
	//private members
	private:
		Gtk::Grid* grid;
		Gtk::TreeView *m_TreeView;
		Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
		Gtk::Button* skip;
		Gtk::TextView *m_TextView;
		string sort(int totalApps, stringstream& output, int sortType);

	protected:
		Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
		Gtk::CheckButton* options;
		int type;
		Gtk::Button* select;
		Gtk::Button* cancel;
		Gtk::Button* saveB;
		Gtk::Button* deleteB;

	//public members
	public:
		CourseListMenu(int Type);
		~CourseListMenu();
		Gtk::Grid*     getGrid();
		Gtk::Button*   getCancel();
		Gtk::Button*   getSkip();
		Gtk::Button*   getSelect();
		Gtk::Button*   getDelete();
		Gtk::TreeView* getTreeView();
		string getString();
		void setString(string app);
		int getType();
		int getSelectedIndex();
		void loadCourseList();
		void loadApplications(Student&, string);
		void loadRelatedCourses(Application&);
		void loadAssistedCourses(Application&);
		void loadWorkExperience(Application&);

		class ModelColumns : public Gtk::TreeModel::ColumnRecord	{
			public:
				ModelColumns(){
					add(m_col_name); 
				}
			Gtk::TreeModelColumn<Glib::ustring> m_col_name;

		};

		ModelColumns m_Columns;
		Gtk:: ScrolledWindow m_ScrolledWindow;
		Gtk:: ScrolledWindow m_ScrolledWindow2;
};

#endif
