#include "LoginMenu.h"
//LoginMenu source file

//Default constructor
LoginMenu::LoginMenu()	{
	//Create box	
	box = new Gtk::VBox();

	//Create neccessary buttons
	studentB = new Gtk::Button("STUDENT", false);
	studentB->set_size_request(150, 90);

	teacherB = new Gtk::Button("TEACHER", false);
	teacherB->set_size_request(150, 90); 

	//Add buttons to the box
	box->pack_start(*studentB, Gtk::PACK_SHRINK, 15);
	box->pack_start(*teacherB, Gtk::PACK_SHRINK, 15);

	add(*box);
}

// destructor 
LoginMenu::~LoginMenu()	{
	delete(box);
	delete(studentB);
	delete(teacherB);
}

//Returns the box when called
Gtk::VBox* LoginMenu::getBox()	{
	return box;
}

//Returns the student button when called
Gtk::Button* LoginMenu::getStudentButton()	{
	return studentB;
}

//Returns the teacher button when called
Gtk::Button* LoginMenu::getTeacherButton()	{
	return teacherB;
}
