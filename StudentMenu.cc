//StudentMenu source file

#include "StudentMenu.h"

//Default constructor
StudentMenu::StudentMenu()	{
	//Create frame	
	box = new Gtk::VBox();
	
	//Create neccessary buttons
	createB = new Gtk::Button("CREATE APPLICATION", false);
	createB->set_size_request(300, 60);

	editB = new Gtk::Button("EDIT APPLICATION", false);
	editB->set_size_request(300, 60); 
	editB->set_sensitive(false);

	cancelB = new Gtk::Button("CANCEL", false);
	cancelB->set_size_request(300, 60);

	//Add buttons to the frame
	box->pack_start(*createB);
	box->pack_start(*editB);
	box->pack_start(*cancelB);

	add(*box);
}

StudentMenu::~StudentMenu()	{
	delete(box);
	delete(createB);
	delete(editB);
	delete(cancelB);
}
//Returns the frame when called
Gtk::Box* StudentMenu::getBox()	{
	return box;
}

//Returns the create button when called
Gtk::Button* StudentMenu::getCreateButton()	{
	return createB;
}

//Returns the edit button when called
Gtk::Button* StudentMenu::getEditButton()	  {
	return editB;
}

//Returns the cancel button when called
Gtk::Button* StudentMenu::getCancelButton(){
	return cancelB;
}
