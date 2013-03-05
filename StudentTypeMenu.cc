//StudentTypeMenu source file

//Include statements
#include "StudentTypeMenu.h"

StudentTypeMenu::StudentTypeMenu()	{
	//Create box	
	box = new Gtk::VBox();

	//Create neccessary buttons
	undergrad = new Gtk::Button("UNDERGRADUATE", false);
	undergrad->set_size_request(300, 60);

	grad = new Gtk::Button("GRADUATE", false);
	grad->set_size_request(300, 60); 

	//Add buttons to the box
	box->pack_start(*undergrad, Gtk::PACK_SHRINK, 15);
	box->pack_start(*grad, Gtk::PACK_SHRINK, 15);

	add(*box);
}

//Default destructor
StudentTypeMenu::~StudentTypeMenu()	{
	delete box;
	delete undergrad;
	delete grad;
}

//Returns the box when called
Gtk::VBox* StudentTypeMenu::getBox()	{
	return box;
}
//Returns the underad button when called
Gtk::Button* StudentTypeMenu::getUndergrad()	{
	return undergrad;
}

//Returns the grad button when called
Gtk::Button* StudentTypeMenu::getGrad()	{
	return grad;
}
