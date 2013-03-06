//TACourseMenu source file

//Include statements
#include "TACourseMenu.h"
#include "AssistantCourse.h"
#include <iostream>

TACourseMenu::TACourseMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addCourseB = new Gtk::Button("ADD ANOTHER COURSE");
	nextB = new Gtk::Button("ADD AND CONTINUE");

	//Create labels
	relatedCourseL = new Gtk::Label("TA COURSE");
	relatedCourseL->set_size_request(70, 30);

	termL = new Gtk::Label("TERM");
	termL->set_size_request(70, 30);
	
	yearL = new Gtk::Label("YEAR");
	yearL->set_size_request(70, 30);
	
	supervisorL = new Gtk::Label("SUPERVISOR");
	supervisorL->set_size_request(70, 30);

	//Set combo boxes and entry boxes
	termD = new Gtk::ComboBoxText();
	termD->set_size_request(70, 30);

	yearT = new Gtk::Entry();
	yearT->set_size_request(70, 30);

	supervisorT = new Gtk::Entry();
	supervisorT->set_size_request(70, 30);
	term_refTreeModel = Gtk::ListStore::create(term_Columns);
	termD->set_model(term_refTreeModel);
	Gtk::TreeModel::Row row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Fall";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Winter";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Summer";

	grid->attach(*relatedCourseL,0,0,2,1);
	grid->attach(*termL,0,1,1,1);
	grid->attach(*termD,1,1,1,1);
	grid->attach(*yearL,0,2,1,1);
	grid->attach(*yearT,1,2,1,1);
	grid->attach(*supervisorL,0,3,1,1);
	grid->attach(*supervisorT,1,3,1,1);
	grid->attach(*addCourseB,0,4,2,1);
	grid->attach(*nextB,0,5,2,1);

	add(*grid);
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

Gtk::ComboBoxText* TACourseMenu::getTerm()	{
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

int TACourseMenu::checkInput()	{
	//Variable storing boolean result
	bool result = true;
	//Checks term
	if(termD->get_active_row_number() == -1)	{
		result = false;
	}
	//Checks duties
	if(!AssistantCourse::checkYear(yearT->get_text()))	{
		setYear("");
		result = false;
	}

	//Checks if duration selected
	if(!AssistantCourse::checkSupervisor(supervisorT->get_text()))	{
		setSupervisor("");
		result = false;
	}
	//Returns result
	return result;
}

//Applies menu info to undergrad
void TACourseMenu::applyUnderTACourse(Undergrad *undergrad)	{
	if(undergrad != 0)	{
		undergrad->getApplications()->back()->getAssisted()->back()->setTerm(getTerm()->get_active_text());
		undergrad->getApplications()->back()->getAssisted()->back()->setYear(getYear()->get_text());
		undergrad->getApplications()->back()->getAssisted()->back()->setSupervisor(getSupervisor()->get_text());
	}
}

//Applies menu info to grad
void TACourseMenu::applyGradTACourse(Grad *grad)	{
	if(grad != 0)	{
		grad->getApplications()->back()->getAssisted()->back()->setTerm(getTerm()->get_active_text());
		grad->getApplications()->back()->getAssisted()->back()->setYear(getYear()->get_text());
		grad->getApplications()->back()->getAssisted()->back()->setSupervisor(getSupervisor()->get_text());
	}
}
