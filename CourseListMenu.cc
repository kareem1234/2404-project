//CourseListMenu source file

#include "CourseListMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>

//Default constructor
CourseListMenu::CourseListMenu(int Type){
	type = Type;
	grid = new Gtk::Grid();
	cancel = new Gtk::Button("CANCEL");
	select= new Gtk::Button("SELECT");
	select->set_sensitive(false);
	m_TreeView = new Gtk::TreeView;
	m_TextView = new Gtk::TextView;
	

	m_ScrolledWindow.add(*m_TreeView);
	m_ScrolledWindow.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		
		
	if(type == 1){
		m_ScrolledWindow2.add(*m_TextView);
		m_ScrolledWindow2.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		m_refTextBuffer = Gtk::TextBuffer::create();
		m_TextView->set_buffer(m_refTextBuffer);
	}

	cancel->set_size_request(70,30);
    	select->set_size_request(70,30);
	m_ScrolledWindow.set_size_request(300,400);

	if(type == 0){
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*cancel,0,3,1,1);
		grid->attach(*select,1,3,1,1);	
	}else if(type == 1){
		grid->attach(m_ScrolledWindow,0,0,2,2);
		grid->attach(m_ScrolledWindow2,0,2,3,3);
		grid->attach(*cancel,0,5,1,1);
		grid->attach(*select,1,5,1,1);
	} else if (type == 3 || type == 4)	{
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*select,0,3,2,1);
	}

	// setup courseList
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView->set_model(m_refTreeModel);
	loadCourseList();
	if(type == 3)	m_TreeView->append_column("RELATED COURSE", m_Columns.m_col_name);
	else if (type == 4)	m_TreeView->append_column("TA COURSE LIST", m_Columns.m_col_name);
	else	m_TreeView->append_column("COURSE LIST", m_Columns.m_col_name);

	add(*grid);
}

CourseListMenu::~CourseListMenu()	{

	delete(grid);

	delete(cancel);

	delete(select);

	delete(m_TreeView);

	delete(m_TextView);

}
int CourseListMenu::getType(){
	return type;
}

//Loads list of courses into GUI list
int CourseListMenu::loadCourseList(){
	
	ifstream loadFile("courseList.txt", ios::in);
	
	if(!loadFile){
		return 0;
	}
	
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	char line[50];
	// getting lines from file
	while(!loadFile.eof()){
		loadFile.getline(line,50);
		row[m_Columns.m_col_name] = line;	
		row = *(m_refTreeModel->append());
	}

	return 1;
}

//Returns frame when called
Gtk::Grid* CourseListMenu::getGrid()  {
	return grid;
	
}

//Returns cancel button when called
Gtk::Button* CourseListMenu::getCancel(){
	return cancel;
}

//Returns select button when called
Gtk::Button* CourseListMenu::getSelect(){
	return select;
}

string CourseListMenu::getString(){
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter)  {
  		Gtk::TreeModel::Row row = *iter;
		string s = row->get_value(m_Columns.m_col_name);
		return s;
	}
}
void CourseListMenu::setString(string app){
	m_refTextBuffer->set_text(app);

}
Gtk::TreeView* CourseListMenu::getTreeView(){
	return m_TreeView;
}

