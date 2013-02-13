//TACourseMenu source file

//Include statements
#include "TACourseMenu.h"
#include<iostream>

TACourseMenu::TACourseMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addCourseB = new Gtk::Button("ADD COURSE");
	//addCourseB->set_sensitive(false);
	nextB = new Gtk::Button("NEXT");

	//Create labels
	relatedCourseL = new Gtk::Label("TA'D COURSE");
	relatedCourseL->set_size_request(70, 30);

	termL = new Gtk::Label("TERM");
	termL->set_size_request(70, 30);
	
	yearL = new Gtk::Label("YEAR");
	yearL->set_size_request(70, 30);
	
	supervisorL = new Gtk::Label("SUPERVISOR");
	supervisorL->set_size_request(70, 30);

	//Set combo boxes and entry boxes
	termD = new Gtk::ComboBox();
	termD->set_size_request(70, 30);

	yearT = new Gtk::Entry();
	yearT->set_size_request(70, 30);

	supervisorT = new Gtk::Entry();
	supervisorT->set_size_request(70, 30);
	cout<<"yup problem in the constructor3"<<endl;
	term_refTreeModel = Gtk::ListStore::create(term_Columns);
	termD->set_model(term_refTreeModel);
	cout<<"yup problem in the constructor2"<<endl;
	Gtk::TreeModel::Row row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Fall";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Winter";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Summer";

	termD->pack_start(term_Columns.m_col_value);
	cout<<"yup problem in the constructor1"<<endl;
	grid->attach(*relatedCourseL,0,0,2,1);
	grid->attach(*termL,0,1,1,1);
	grid->attach(*termD,1,1,1,1);
	grid->attach(*yearL,0,2,1,1);
	grid->attach(*yearT,1,2,1,1);
	grid->attach(*supervisorL,0,3,1,1);
	grid->attach(*supervisorT,1,3,1,1);
	grid->attach(*addCourseB,0,4,1,1);
	grid->attach(*nextB,1,4,1,1);

	add(*grid);
	cout<<"yup problem in the constructor"<<endl;
}
	
TACourseMenu::~TACourseMenu()	{
	delete(grid);
	delete(addCourseB);
	delete(nextB);
	delete(relatedCourseL);
	delete(termD);
	delete(yearT);
	delete(supervisorT);
	delete(termL);
	delete(yearL);
	delete(supervisorL);
}

Gtk::Grid* TACourseMenu::getGrid()	{
	return grid;
}

Gtk::Button* TACourseMenu::getAddButton()	{
	return addCourseB;
}

Gtk::Button* TACourseMenu::getNextButton()	{
	return nextB;
}

Gtk::ComboBox* TACourseMenu::getTerm()	{
	return termD;
}

Gtk::Entry* TACourseMenu::getYear()	{
	return yearT;
}

Gtk::Entry* TACourseMenu::getSupervisor()	{
	return supervisorT;
}

void TACourseMenu::setYear(string y)	{
	yearT->set_text(y);
}

void TACourseMenu::setSupervisor(string name)	{
	supervisorT->set_text(name);
}
