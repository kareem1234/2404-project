//StudentMenu source file

#include "TeacherMenu.h"

//Default constructor
TeacherMenu::TeacherMenu(){
	//Create frame	
	box = new Gtk::VBox();
	
	//Create neccessary buttons
	

	viewApp = new Gtk::Button("ASSIGN A SUCCESFUL APPLICATION", false);
	viewApp->set_size_request(300, 60); 

	all = new Gtk::Button("VIEW ALL APPLICATIONS",false);
	all->set_size_request(300,60);

	viewSummary = new Gtk::Button("VIEW  PENDING APPLICATIONS", false);
	viewSummary->set_size_request(300, 60); 
	

	editTa = new Gtk::Button("EDIT A TA EVALUATION", false);
	editTa->set_size_request(300, 60); 
	editTa->set_sensitive(false);

	viewAssigned = new Gtk::Button("VIEW SUCCESSFUL APPLICATIONS", false);
	viewAssigned->set_size_request(300, 60); 


	cancelB = new Gtk::Button("CANCEL", false);
	cancelB->set_size_request(300, 60); 

	//Add buttons to the frame
	box->pack_start(*viewApp);
	box->pack_start(*all);
	box->pack_start(*editTa);
	box->pack_start(*viewSummary);
	box->pack_start(*viewAssigned);
	box->pack_start(*cancelB);

	add(*box);
}

TeacherMenu::~TeacherMenu()	{
	delete(box);
	delete(viewApp);
	delete(editTa);
	delete(cancelB);
	delete(viewAssigned);
	delete(viewSummary);
	delete(all);
}

Gtk::VBox* TeacherMenu::getBox()	{
	return box;
}

Gtk::Button* TeacherMenu::getAppButton(){
	return viewApp;
}
Gtk::Button* TeacherMenu::getSummaryButton(){
	return viewSummary;

}
Gtk::Button* TeacherMenu::getAssignedButton(){
	return viewAssigned;
}
Gtk::Button* TeacherMenu::getEditButton(){
	return editTa;
}
Gtk::Button* TeacherMenu::getCancelButton(){
	return cancelB;
}

Gtk::Button* TeacherMenu:: getAllButton(){
	return all;
}
	






