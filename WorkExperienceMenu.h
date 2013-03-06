//WorkExperienceMenu header file

#ifndef WORKEXPERIENCEMENU_H
#define WORKEXPERIENCEMENU_H

#include "Undergrad.h"
#include "Grad.h"
#include <gtkmm.h>
#include <string>
using namespace std;

//Define WorkExperienceMenu class
class WorkExperienceMenu : public Gtk::Frame 	{
	//Private data members
	private:
		
		class ModelColumns : public Gtk::TreeModel::ColumnRecord	{
		public:
			ModelColumns()	{	add(m_col_value);	}

			Gtk::TreeModelColumn<Glib::ustring> m_col_value;
		};

		Gtk::Grid* grid;
		Gtk::Button* addB;
		Gtk::Button* cancelB;
		Gtk::Button* skipSubmitB;
		Gtk::Button* submitB;
		Gtk::Label* experienceL;
		Gtk::Label* titleL;
		Gtk::Label* dutiesL;
		Gtk::Label* durationL;
		Gtk::Label* dateL;
		Gtk::Label* toL;
		Gtk::Entry* titleT;
		Gtk::TextView* dutiesT;
		Gtk::ScrolledWindow dutiesW; 
		Gtk::ComboBoxText* durationD;
		Gtk::ComboBoxText* startMonth;
		Gtk::ComboBoxText* startYear;
		Gtk::ComboBoxText* endMonth;
		Gtk::ComboBoxText* endYear;
		
		ModelColumns duration_Columns;
		ModelColumns month_Columns;
		ModelColumns year_Columns;

		Glib::RefPtr<Gtk::ListStore> duration_refTreeModel;
		Glib::RefPtr<Gtk::ListStore> month_refTreeModel;
		Glib::RefPtr<Gtk::ListStore> year_refTreeModel;

	//Public data members
	public:
		WorkExperienceMenu();
		~WorkExperienceMenu();
		Gtk::Grid* getGrid();
		Gtk::Button* getAddButton();
		Gtk::Button* getCancelButton();
		Gtk::Button* getSkipButton();
		Gtk::Button* getSubmitButton();
		Gtk::Entry* getTitle();
		Gtk::TextView* getDuties();
		Gtk::ComboBoxText* getDuration();
		Gtk::ComboBoxText* getStartMonth();
		Gtk::ComboBoxText* getStartYear();
		Gtk::ComboBoxText* getEndMonth();
		Gtk::ComboBoxText* getEndYear();
		string getStartDate();
		string getEndDate();
		void setDuties(string);
		string getDutiesText();
		int checkInput();
		void applyUnderWorkExperience(Undergrad*);
		void applyGradWorkExperience(Grad*);
};

#endif
