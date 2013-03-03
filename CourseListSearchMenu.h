
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
	private:
		string sortByGpa(int totalApps, stringstream& output, stringstream& newOutput);


};
