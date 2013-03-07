
#include <gtkmm.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "CourseListMenu.h"
using namespace std;


class CourseListSearchMenu : public CourseListMenu {

	public: 
		CourseListSearchMenu(int type);
		void findApp();
		void checked();
		void print();
		Gtk::CheckButton* getOptions();
		Gtk::Button* getSave();
	private:
		string sort(int totalApps, stringstream& output, int sortType);


};
