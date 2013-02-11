//WorkExperienceMenu source file

//Include statements
#include "WorkExperienceMenu.h"
#include <sstream>

WorkExperienceMenu::WorkExperienceMenu()	{
	//Create grid
	grid = new Gtk::Grid();
	addB = new Gtk::Button("ADD EXPERIENCE");
	addB->set_sensitive(false);
	nextB = new Gtk::Button("NEXT");

	//Create labels
	experienceL = new Gtk::Label("WORK EXPERIENCE");
	experienceL->set_size_request(70, 30);

	responsabilitiesL = new Gtk::Label("RESPONSIBILITIES");
	responsabilitiesL->set_size_request(70, 30);
	
	durationL = new Gtk::Label("DURATION");
	durationL->set_size_request(70, 30);
	
	dateL = new Gtk::Label("START AND END DATES (month/year)");
	dateL->set_size_request(70, 30);

	toL = new Gtk::Label("TO");
	toL->set_size_request(30, 30);

	//Set combo boxes and entry boxes
	responsabilitiesT = new Gtk::TextView();
	responsabilitiesT->set_size_request(70,60);

	responsabilitiesW.add(*responsabilitiesT);
	responsabilitiesW.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	durationD = new Gtk::ComboBox();
	durationD->set_size_request(70, 30);

	startMonth = new Gtk::ComboBox();
	startMonth->set_size_request(70, 30);

	startYear = new Gtk::ComboBox();
	startYear->set_size_request(70, 30);

	endMonth = new Gtk::ComboBox();
	endMonth->set_size_request(70, 30);

	endYear = new Gtk::ComboBox();
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

	durationD->pack_start(duration_Columns.m_col_value);

	startMonth->pack_start(month_Columns.m_col_value);
	endMonth->pack_start(month_Columns.m_col_value);

	startYear->pack_start(year_Columns.m_col_value);
	endYear->pack_start(year_Columns.m_col_value);

	grid->attach(*experienceL,0,0,6,1);
	grid->attach(*responsabilitiesL,0,1,1,1);
	grid->attach(responsabilitiesW,1,1,5,2);
	grid->attach(*durationL,0,3,1,1);
	grid->attach(*durationD,1,3,5,1);
	grid->attach(*dateL,0,4,1,1);
	grid->attach(*startMonth,1,4,1,1);
	grid->attach(*startYear,2,4,1,1);
	grid->attach(*toL,3,4,1,1);
	grid->attach(*endMonth,4,4,1,1);
	grid->attach(*endYear,5,4,1,1);
	grid->attach(*addB,0,5,2,1);
	grid->attach(*nextB,2,5,4,1);

	add(*grid);
}
	
WorkExperienceMenu::~WorkExperienceMenu()	{
	delete grid;
	delete addB;
	delete nextB;
	delete experienceL;
	delete responsabilitiesL;
	delete durationL;
	delete dateL;
	delete toL;
	delete responsabilitiesT;
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

Gtk::Button* WorkExperienceMenu::getNextButton()	{
	return nextB;
}

Gtk::TextView* WorkExperienceMenu::getResponsabilities()	{
	return responsabilitiesT;
}

Gtk::ComboBox* WorkExperienceMenu::getDuration()	{
	return durationD;
}

Gtk::ComboBox* WorkExperienceMenu::getStartMonth()	{
	return startMonth;
}

Gtk::ComboBox* WorkExperienceMenu::getStartYear()	{
	return startYear;
}

Gtk::ComboBox* WorkExperienceMenu::getEndMonth()	{
	return endMonth;
}

Gtk::ComboBox* WorkExperienceMenu::getEndYear()	{
	return endYear;
}

void WorkExperienceMenu::setResponsabilities(string t)	{
	Glib::RefPtr<Gtk::TextBuffer> buffer;
	buffer->set_text(t);	
	responsabilitiesT->set_buffer(buffer);
}
