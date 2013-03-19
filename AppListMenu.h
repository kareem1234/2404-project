#include <gtkmm.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class AppListMenu : public Gtk:: Frame {


	private:
		Gtk::Grid* grid;
		Gtk::TreeView *m_TreeView;
		Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
		Gtk::Button* select;
		Gtk::Button* cancel;
		void loadAppList();
		void editSaveLog(string app);

	public: 
		AppListMenu();
		~AppListMenu();
		Gtk::Grid*     getGrid();
		Gtk::Button*   getCancel();
		Gtk::Button*   getSelect();
		Gtk::TreeView* getTreeView();
		void assignApp();
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
