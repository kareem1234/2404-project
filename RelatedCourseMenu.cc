//RelatedCourseMenu source file

//Include statements
#include "RelatedCourseMenu.h"

RelatedCourseMenu::RelatedCourseMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addCourseB = new Gtk::Button("ADD COURSE");
	addCourseB->set_sensitive(false);
	nextB = new Gtk::Button("NEXT");

	//Create labels
	relatedCourseL = new Gtk::Label("RELATED COURSE");
	relatedCourseL->set_size_request(70, 30);

	termL = new Gtk::Label("TERM");
	termL->set_size_request(70, 30);
	
	yearL = new Gtk::Label("YEAR");
	yearL->set_size_request(70, 30);
	
	finalL = new Gtk::Label("FINAL GRADE");
	finalL->set_size_request(70, 30);

	//Set combo boxes and entry boxes
	termD = new Gtk::ComboBox();
	termD->set_size_request(70, 30);

	yearT = new Gtk::Entry();
	yearT->set_size_request(70, 30);

	finalT = new Gtk::Entry();
	finalT->set_size_request(70, 30);

	term_refTreeModel = Gtk::ListStore::create(term_Columns);
	termD->set_model(term_refTreeModel);

	Gtk::TreeModel::Row row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Fall";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Winter";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Summer";

	termD->pack_start(term_Columns.m_col_value);

	grid->attach(*relatedCourseL,0,0,2,1);
	grid->attach(*termL,0,1,1,1);
	grid->attach(*termD,1,1,1,1);
	grid->attach(*yearL,0,2,1,1);
	grid->attach(*yearT,1,2,1,1);
	grid->attach(*finalL,0,3,1,1);
	grid->attach(*finalT,1,3,1,1);
	grid->attach(*addCourseB,0,4,1,1);
	grid->attach(*nextB,1,4,1,1);

	add(*grid);
}
	
RelatedCourseMenu::~RelatedCourseMenu()	{
	delete(grid);
	delete(addCourseB);
	delete(nextB);
	delete(relatedCourseL);
	delete(termD);
	delete(yearT);
	delete(finalT);
	delete(termL);
	delete(yearL);
	delete(finalL);
}

Gtk::Grid* RelatedCourseMenu::getGrid()	{
	return grid;
}

Gtk::Button* RelatedCourseMenu::getAddButton()	{
	return addCourseB;
}

Gtk::Button* RelatedCourseMenu::getNextButton()	{
	return nextB;
}

Gtk::ComboBox* RelatedCourseMenu::getTerm()	{
	return termD;
}

Gtk::Entry* RelatedCourseMenu::getYear()	{
	return yearT;
}

Gtk::Entry* RelatedCourseMenu::getFinalGrade()	{
	return finalT;
}

void RelatedCourseMenu::setYear(string y)	{
	yearT->set_text(y);
}

void RelatedCourseMenu::setFinalGrade(string grade)	{
	finalT->set_text(grade);
}
