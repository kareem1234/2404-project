//CourseList header file

#ifndef COURSELIST_H
#define COURSELIST_H

#include <gtkmm.h>
#include <string>
using namespace std;

//Define CourseList class
class CourseListMenu : public Gtk::Frame {
	//private members
	private:
		Gtk::Grid* grid;
		Gtk::TreeView *m_TreeView;
		Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
		Gtk::Button* cancel;
		Gtk::Button* select;
		int loadCourseList();
	//public members
	public:
		CourseListMenu(int type);
		~CourseListMenu();
		Gtk::Grid*     getGrid();
		Gtk::Button*   getCancel();
		Gtk::Button*   getSelect();
		Gtk::TreeView* getTreeView();
		string getString();

		class ModelColumns : public Gtk::TreeModel:: ColumnRecord	{
			public:
				ModelColumns(){
					add(m_col_name); 
				}
			Gtk::TreeModelColumn<Glib::ustring> m_col_name;

		};

		ModelColumns m_Columns;
		Gtk:: ScrolledWindow m_ScrolledWindow;
};

#endif
