//VerificationMenu source file

//Include statements
#include "VerificationMenu.h"
#include "Student.h"

VerificationMenu::VerificationMenu()	{
	//Create box	
	box = new Gtk::VBox();

	numL = new Gtk::Label("ENTER YOUR STUDENT NUMBER BELOW");
	numL->set_size_request(300, 30);
	
	numT = new Gtk::Entry();
	numT->set_size_request(300, 30);

	submit = new Gtk::Button("SUBMIT", false);
	submit->set_size_request(300, 30);

	//Add buttons to the box
	box->pack_start(*numL, Gtk::PACK_SHRINK, 15);
	box->pack_start(*numT, Gtk::PACK_SHRINK, 0);
	box->pack_start(*submit, Gtk::PACK_SHRINK, 10);

	add(*box);
}

//Default destructor
VerificationMenu::~VerificationMenu()	{
	delete box;
	delete numL;
	delete numT;
	delete submit;
}

//Returns the box when called
Gtk::VBox* VerificationMenu::getBox()	{
	return box;
}

//Returns the number field when called
Gtk::Entry* VerificationMenu::getNumber()	{
	return numT;
}

//Return submit button when called
Gtk::Button* VerificationMenu::getSubmit()	{
	return submit;
}

bool VerificationMenu::checkInput()	{
	if(!Student::checkStuNum(numT->get_text()))	return false;
}
