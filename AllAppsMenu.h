#include <gtkmm.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

class AllAppsMenu :  public Gtk::Frame  {

	private:
		int index;
		int total;
		string  apps[100]; 
		Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
		Gtk::Button* previous;
		Gtk::Button* next;
		Gtk::Button* cancel;
		Gtk::Button* search;
		Gtk::Label*  searchOptions;
		Gtk::Label*  searchWord;
		Gtk::TextView *m_TextView;
		Gtk::Grid* grid;
		Gtk::Entry* searchTerm;
		Gtk::RadioButton* appNumber;
		Gtk::RadioButton* stuNumber;
		Gtk::RadioButton* name;


	public:
		AllAppsMenu();
		~AllAppsMenu();
		Gtk::TextView* getTextView();
		Gtk::Button* getPrevious();
		Gtk::RadioButton* getName();
		Gtk::RadioButton* getAppNum();
		Gtk::RadioButton* getStuNum();
		Gtk::Button* getNext();
		Gtk::Button* getCancel();
		Gtk::Button* getSearch();
		Gtk::Grid* getGrid();
		void setControls();
		void setText();
		bool searchCheck(string appNum,string stuNum,string firstName, string lastName);
		void clear();
		void nextClicked();
		void prevClicked();
		void doSearch();
		void getInfo(stringstream& output, istringstream& toParse);

		
		Gtk:: ScrolledWindow m_ScrolledWindow;






};
