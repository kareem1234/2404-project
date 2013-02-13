//RelatedCourseMenu source file

//Include statements
#include "RelatedCourseMenu.h"
#include "Course.h"

RelatedCourseMenu::RelatedCourseMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addCourseB = new Gtk::Button("ADD COURSE");
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
	termD = new Gtk::ComboBoxText();
	termD->set_size_request(70, 30);

	yearT = new Gtk::Entry();
	yearT->set_size_request(70, 30);

	finalD = new Gtk::ComboBoxText();
	finalD->set_size_request(70, 30);

	term_refTreeModel = Gtk::ListStore::create(term_Columns);
	termD->set_model(term_refTreeModel);

	grade_refTreeModel = Gtk::ListStore::create(grade_Columns);
	finalD->set_model(grade_refTreeModel);

	Gtk::TreeModel::Row row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Fall";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Winter";
	row = *(term_refTreeModel->append());
	row[term_Columns.m_col_value] = "Summer";

	Gtk::TreeModel::Row row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "A+";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "A";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "A-";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "B+";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "B";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "B-";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "C+";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "C";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "C-";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "D+";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "D";
	row1 = *(grade_refTreeModel->append());
	row1[grade_Columns.m_col_value] = "D-";

	grid->attach(*relatedCourseL,0,0,2,1);
	grid->attach(*termL,0,1,1,1);
	grid->attach(*termD,1,1,1,1);
	grid->attach(*yearL,0,2,1,1);
	grid->attach(*yearT,1,2,1,1);
	grid->attach(*finalL,0,3,1,1);
	grid->attach(*finalD,1,3,1,1);
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
	delete(finalD);
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

Gtk::ComboBoxText* RelatedCourseMenu::getTerm()	{
	return termD;
}

Gtk::Entry* RelatedCourseMenu::getYear()	{
	return yearT;
}

Gtk::ComboBoxText* RelatedCourseMenu::getFinalGrade()	{
	return finalD;
}

void RelatedCourseMenu::setYear(string y)	{
	yearT->set_text(y);
}

bool RelatedCourseMenu::checkInput()	{
	//Variable storing boolean result
	bool result = true;
	
	//Checks term selected
	if(termD->get_active_row_number() == -1)	{
		result = false;
	}
	//Checks year
	if(!Course::checkYear(yearT->get_text()))	{
		yearT->set_text("");
		result = false;
	}
	//Checks final selected
	if(finalD->get_active_row_number() == -1)	{
		result = false;
	}

	return result;
}
