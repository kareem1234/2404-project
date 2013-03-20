//CourseListMenu source file

//Include statements
#include "CourseListMenu.h"
using namespace std;

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

//Default constructor
CourseListMenu::CourseListMenu(int Type){
	options = 0;
	saveB = 0;
	discardB = 0;
	addB = 0;
	discardB = 0;

	type = Type;
	grid = new Gtk::Grid();
	cancel = new Gtk::Button("CANCEL");
	skip = new Gtk::Button("SKIP");
	select = new Gtk::Button("SELECT");
	select->set_sensitive(false);
	m_TreeView = new Gtk::TreeView;
	m_TextView = new Gtk::TextView;
	
	//Make scrolling view
	m_ScrolledWindow.add(*m_TreeView);
	m_ScrolledWindow.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		
	//Depending on the type the list looks different and has different behaviour
	if(type == 1 || type == 2){
		m_ScrolledWindow2.add(*m_TextView);
		m_TextView->set_editable(false);
		m_ScrolledWindow2.set_policy(Gtk:: POLICY_AUTOMATIC,Gtk:: POLICY_AUTOMATIC);
		m_refTextBuffer = Gtk::TextBuffer::create();
		m_TextView->set_buffer(m_refTextBuffer);
		m_ScrolledWindow2.set_size_request(80,100);
	}

	cancel->set_size_request(70,30);
    	select->set_size_request(70,30);
	skip->set_size_request(70,30);
	m_ScrolledWindow.set_size_request(250,400);

	if(type == 0 || type == 111)	{
		cout << "HI" << endl;
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*select,0,3,2,1);	
		grid->attach(*cancel,0,4,2,1);
	} else if(type == 1 || type == 2)	{
		cout << "Hi 2" << endl;
		saveB = new Gtk::Button("SAVE APPLICATIONS");
		saveB->set_sensitive(false);
		options = new Gtk::CheckButton("VIEW ALL APPLICATIONS");
		grid->attach(*options,0,0,2,1);
		grid->attach(m_ScrolledWindow,0,1,2,2);
		grid->attach(m_ScrolledWindow2,0,3,2,1);
		grid->attach(*select,0,4,2,1);		
		grid->attach(*cancel,0,5,2,1);
		grid->attach(*saveB,0,6,2,1);
	} else if(type == 222)	{
		cout << "Hi 3" << endl;
		addB = new Gtk::Button("ADD EXPERIENCE");
		saveB = new Gtk::Button("SAVE CHANGES");
		discardB = new Gtk::Button("DISCARD CHANGES");
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*addB,0,3,2,1);
		grid->attach(*select,0,4,2,1);	
		grid->attach(*cancel,0,5,2,1);
		grid->attach(*saveB,0,6,2,1);
		grid->attach(*discardB,0,7,2,1);	
	} else if (type >= 3)	{
		grid->attach(m_ScrolledWindow,0,0,2,3);
		grid->attach(*select,0,3,2,1);
		grid->attach(*skip,0,4,2,1);
	}

	//Setup courseList
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView->set_model(m_refTreeModel);

	if(type == 3)	m_TreeView->append_column("RELATED COURSE", m_Columns.m_col_name);
	else if(type == 4)	m_TreeView->append_column("TA COURSE LIST", m_Columns.m_col_name);
	else if(type == 111)	m_TreeView->append_column("APPLICATIONS", m_Columns.m_col_name);
	else if(type == 222)	m_TreeView->append_column("WORK EXPERIENCE", m_Columns.m_col_name);
	else	m_TreeView->append_column("COURSE LIST", m_Columns.m_col_name);

	add(*grid);
}

//Default destructor
CourseListMenu::~CourseListMenu()	{
	delete(grid);
	delete(cancel);
	delete(skip);
	delete(select);
	delete(saveB);
	delete(addB);
	delete(discardB);
	delete(m_TreeView);
	delete(m_TextView);
}

//Returns int type describing what list it is
int CourseListMenu::getType()	{
	return type;
}

//Loads list of courses into GUI list
void CourseListMenu::loadCourseList()	{
	
	ifstream loadFile("courseList.txt", ios::in);
	
	if(!loadFile){
		return;
	}
	
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	char line[50];
	// getting lines from file
	while(!loadFile.eof()){
		loadFile.getline(line,50);
		row[m_Columns.m_col_name] = line;	
		row = *(m_refTreeModel->append());
	}
}

void CourseListMenu::loadApplications(Student &stu, string type)	{
	int i;
	myQ<Application> *queue = stu.getApplications();
	Gtk::TreeModel::Row row;
	
	for(i = 0; i < queue->length(); i++)	{
		if((*queue)[i]->getStatus() == type)	{
			row = *(m_refTreeModel->append());
			row[m_Columns.m_col_name] = (*queue)[i]->getCourse();
		}		
	}
}

void CourseListMenu::loadRelatedCourses(Application &app)	{
	int i;
	myQ<RelatedCourse> *queue = app.getRelated();
	Gtk::TreeModel::Row row;
	
	for(i = 0; i < queue->length(); i++)	{
		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_name] = (*queue)[i]->getCourseName();
	}
}

void CourseListMenu::loadAssistedCourses(Application &app)	{
	int i;
	myQ<AssistantCourse> *queue = app.getAssisted();
	Gtk::TreeModel::Row row;
	
	for(i = 0; i < queue->length(); i++)	{
		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_name] = (*queue)[i]->getCourseName();
	}
}

void CourseListMenu::loadWorkExperience(Application &app)	{
	int i;
	myQ<WorkExperience> *queue = app.getExperience();
	Gtk::TreeModel::Row row;
	
	for(i = 0; i < queue->length(); i++)	{
		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_name] = (*queue)[i]->getTitle();
	}
}

//Returns frame when called
Gtk::Grid* CourseListMenu::getGrid()  {
	return grid;
}

//Returns cancel button when called
Gtk::Button* CourseListMenu::getCancel(){
	return cancel;
}

//Returns skip button when called
Gtk::Button* CourseListMenu::getSkip()	{
	return skip;
}

//Returns select button when called
Gtk::Button* CourseListMenu::getSelect()	{
	return select;
}

//Returns save button when called
Gtk::Button* CourseListMenu::getSave()	{
	return saveB;
}

//Returns discard button when called
Gtk::Button* CourseListMenu::getDiscard()	{
	return discardB;
}

//Returns add button when called
Gtk::Button* CourseListMenu::getAdd()	{
	return addB;
}

//Returns the current selection
string CourseListMenu::getString()	{
	if(options != 0) 
		if(options->get_active()) return "";
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter)  {
  		Gtk::TreeModel::Row row = *iter;
		string s = row->get_value(m_Columns.m_col_name);
		return s;
	}
}

//Sets the courseList textfield if visible
void CourseListMenu::setString(string app){
	m_refTextBuffer->set_text(app);
}

//Returns the tree view
Gtk::TreeView* CourseListMenu::getTreeView(){
	return m_TreeView;
}

