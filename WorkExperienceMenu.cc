//WorkExperienceMenu source file

//Include statements
#include "WorkExperienceMenu.h"
#include "WorkExperience.h"
#include <sstream>
#include <iostream>

WorkExperienceMenu::WorkExperienceMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addB = new Gtk::Button("ADD EXPERIENCE");
	submitB = new Gtk::Button("SUBMIT");

	//Create labels
	experienceL = new Gtk::Label("WORK EXPERIENCE");
	experienceL->set_size_request(70, 30);

	titleL = new Gtk::Label("TITLE");
	titleL->set_size_request(70, 30);

	dutiesL = new Gtk::Label("DUTIES");
	dutiesL->set_size_request(70, 30);
	
	durationL = new Gtk::Label("DURATION");
	durationL->set_size_request(70, 30);
	
	dateL = new Gtk::Label("START AND END DATES (month/year)");
	dateL->set_size_request(70, 30);

	toL = new Gtk::Label("TO");
	toL->set_size_request(30, 30);

	//Set combo boxes and entry boxes
	titleT = new Gtk::Entry();
	titleT->set_size_request(70,30);	

	dutiesT = new Gtk::TextView();
	dutiesT->set_size_request(70,60);

	dutiesW.add(*dutiesT);
	dutiesW.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	durationD = new Gtk::ComboBoxText();
	durationD->set_size_request(70, 30);

	startMonth = new Gtk::ComboBoxText();
	startMonth->set_size_request(70, 30);

	startYear = new Gtk::ComboBoxText();
	startYear->set_size_request(70, 30);

	endMonth = new Gtk::ComboBoxText();
	endMonth->set_size_request(70, 30);

	endYear = new Gtk::ComboBoxText();
	endYear->set_size_request(70, 30);

	duration_refTreeModel = Gtk::ListStore::create(duration_Columns);
	durationD->set_model(duration_refTreeModel);

	month_refTreeModel = Gtk::ListStore::create(month_Columns);
	startMonth->set_model(month_refTreeModel);
	endMonth->set_model(month_refTreeModel);

	year_refTreeModel = Gtk::ListStore::create(year_Columns);
	startYear->set_model(year_refTreeModel);
	endYear->set_model(year_refTreeModel);

	Gtk::TreeModel::Row row1 = *(duration_refTreeModel->append());
	stringstream s;
	for(int i=1; i<11; i++)	{
		s.str("");
		if(i == 1) {
		  s << i << " year";
		} else {
		   s << i << " years";
		}
		row1[duration_Columns.m_col_value] = s.str();
		row1 = *(duration_refTreeModel->append());
	}
	row1[duration_Columns.m_col_value] = "11+ years";

	Gtk::TreeModel::Row row2 = *(month_refTreeModel->append());
	for(int i=1; i<13; i++)	{
		s.str("");
		s << i;
		row2[month_Columns.m_col_value] = s.str();
		if(i != 12)	row2 = *(month_refTreeModel->append());
	}

	Gtk::TreeModel::Row row3 = *(year_refTreeModel->append());
	for(int i=1970; i<2014; i++)	{
		s.str("");
		s << i;
		row3[year_Columns.m_col_value] = s.str();
		if(i != 2013)	row3 = *(year_refTreeModel->append());
	}

	grid->attach(*experienceL,0,0,6,1);
	grid->attach(*titleL,0,1,1,1);
	grid->attach(*titleT,1,1,5,1);
	grid->attach(*dutiesL,0,2,1,1);
	grid->attach(dutiesW,1,2,5,2);
	grid->attach(*durationL,0,4,1,1);
	grid->attach(*durationD,1,4,5,1);
	grid->attach(*dateL,0,5,1,1);
	grid->attach(*startMonth,1,5,1,1);
	grid->attach(*startYear,2,5,1,1);
	grid->attach(*toL,3,5,1,1);
	grid->attach(*endMonth,4,5,1,1);
	grid->attach(*endYear,5,5,1,1);
	grid->attach(*addB,0,6,2,1);
	grid->attach(*submitB,2,6,4,1);

	add(*grid);
}
	
WorkExperienceMenu::~WorkExperienceMenu()	{
	delete grid;
	delete addB;
	delete submitB;
	delete experienceL;
	delete titleL;
	delete dutiesL;
	delete durationL;
	delete dateL;
	delete toL;
	delete titleT;
	delete dutiesT;
	delete durationD;
	delete startMonth;
	delete startYear;
	delete endMonth;
	delete endYear;
}

Gtk::Grid* WorkExperienceMenu::getGrid()	{
	return grid;
}

Gtk::Button* WorkExperienceMenu::getAddButton()	{
	return addB;
}

Gtk::Button* WorkExperienceMenu::getSubmitButton()	{
	return submitB;
}

Gtk::Entry* WorkExperienceMenu::getTitle()	{
	return titleT;
}

Gtk::TextView* WorkExperienceMenu::getDuties()	{
	return dutiesT;
}

Gtk::ComboBoxText* WorkExperienceMenu::getDuration()	{
	return durationD;
}

Gtk::ComboBoxText* WorkExperienceMenu::getStartMonth()	{
	return startMonth;
}

Gtk::ComboBoxText* WorkExperienceMenu::getStartYear()	{
	return startYear;
}

Gtk::ComboBoxText* WorkExperienceMenu::getEndMonth()	{
	return endMonth;
}

Gtk::ComboBoxText* WorkExperienceMenu::getEndYear()	{
	return endYear;
}

void WorkExperienceMenu::setDuties(string t)	{
	Glib::RefPtr<Gtk::TextBuffer> buffer;
	buffer->set_text(t);	
	dutiesT->set_buffer(buffer);
}

string WorkExperienceMenu::getDutiesText()	{
	string s;
	Glib::RefPtr<Gtk::TextBuffer> buffer;	
	buffer = dutiesT->get_buffer();
	return	s = buffer;
}

int WorkExperienceMenu::checkInput()	{
	//Variable storing boolean result
	bool result = true;
	
	//Checks title
	if(!WorkExperience::checkTitle(titleT->get_text()))	{
		titleT->set_text("");
		result = false;
	}

	//Checks duties
	if(!WorkExperience::checkDuties(getDutiesText()))	{
		setDuties("");
		result = false;
	}

	//Checks if duration selected
	if(durationD->get_active_row_number() == -1)	{
		result = false;
	}

	//Checks if dates are selected correctly
	if(startMonth->get_active_row_number() == -1 || startYear->get_active_row_number() == -1
	   || endMonth->get_active_row_number() == -1 || endYear->get_active_row_number() == -1 )	{
		result = false;
	} else	{
		int startY, endY, startM, endM;

		startY = atoi(startYear->get_active_text().c_str());
		endY = atoi(endYear->get_active_text().c_str());
		startM = atoi(startMonth->get_active_text().c_str());
		endM = atoi(endMonth->get_active_text().c_str());

		if(startY > endY)	result = false;
		else if(startY == endY && startM > endM)	result = false;
	}

	
	//Returns result
	return result;
}
