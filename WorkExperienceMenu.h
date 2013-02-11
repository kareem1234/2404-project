//WorkExperienceMenu header file

#ifndef WORKEXPERIENCEMENU_H
#define WORKEXPERIENCEMENU_H

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
		Gtk::Button* nextB;
		Gtk::Label* experienceL;
		Gtk::Label* responsabilitiesL;
		Gtk::Label* durationL;
		Gtk::Label* dateL;
		Gtk::Label* toL;
		Gtk::TextView* responsabilitiesT;
		Gtk::ScrolledWindow responsabilitiesW; 
		Gtk::ComboBox* durationD;
		Gtk::ComboBox* startMonth;
		Gtk::ComboBox* startYear;
		Gtk::ComboBox* endMonth;
		Gtk::ComboBox* endYear;
		
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
		Gtk::Button* getNextButton();
		Gtk::TextView* getResponsabilities();
		Gtk::ComboBox* getDuration();
		Gtk::ComboBox* getStartMonth();
		Gtk::ComboBox* getStartYear();
		Gtk::ComboBox* getEndMonth();
		Gtk::ComboBox* getEndYear();
		void setResponsabilities(string);
};

#endif
