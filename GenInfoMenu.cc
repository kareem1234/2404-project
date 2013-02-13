//GenInfoMenu source file

#include "GenInfoMenu.h"
#include <sstream>

//Default constructor
GenInfoMenu::GenInfoMenu()	{
	//Create frame
	grid = new Gtk::Grid();

	//Create labels
	gpaL = new Gtk::Label("GPA");
	gpaL->set_size_request(70, 30);
	
	cgpaL = new Gtk::Label("CGPA");
	cgpaL->set_size_request(70, 30);
	
	emailL = new Gtk::Label("EMAIL");
	emailL->set_size_request(70, 30);

	yearL = new Gtk::Label("YEAR");
	yearL->set_size_request(70, 30);

	stuNumL = new Gtk::Label("STUDENT NUMBER");
	stuNumL->set_size_request(70, 30);

	majorL = new Gtk::Label("MAJOR");
	majorL->set_size_request(70, 30);
	
	lastNameL = new Gtk::Label("LAST NAME");
	lastNameL->set_size_request(70, 30);
	
	firstNameL = new Gtk::Label("FIRST NAME");
	firstNameL->set_size_request(70, 30);
	
	genInfoL = new Gtk::Label("GENERAL INFO");
	genInfoL->set_size_request(150, 30);
	
	//Create buttons
	nextB = new Gtk::Button("CONTINUE");
	nextB->set_size_request(70,30);
	
	//Create entry fields	
	firstNameT = new Gtk::Entry();
	firstNameT->set_size_request(70,30);

	lastNameT = new Gtk::Entry();
	lastNameT->set_size_request(70,30);
	
	stuNumT = new Gtk::Entry();
	stuNumT->set_size_request(70,30);

	majorT = new Gtk::Entry();
	majorT->set_size_request(70,30);
	
	yearT = new Gtk::Entry();
	yearT->set_size_request(70,30);

	emailT = new Gtk::Entry();
	emailT->set_size_request(70,30);

	gpaT = new Gtk::Entry();
	gpaT->set_size_request(70,30);

	cgpaT = new Gtk::Entry();
	cgpaT->set_size_request(70,30);
	
	//Position the all
	grid->attach(*genInfoL,1,0,2,1);
	grid->attach(*firstNameL,1,1,1,1);
	grid->attach(*firstNameT,2,1,1,1);
	grid->attach(*lastNameL,1,2,1,1);
	grid->attach(*lastNameT,2,2,1,1);	
	grid->attach(*stuNumL,1,3,1,1);	
	grid->attach(*stuNumT,2,3,1,1);
	grid->attach(*majorL,1,4,1,1);	
	grid->attach(*majorT,2,4,1,1);	
	grid->attach(*emailL,1,5,1,1);	
	grid->attach(*emailT,2,5,1,1);	
	grid->attach(*cgpaL,1,6,1,1);	
	grid->attach(*cgpaT,2,6,1,1);	
	grid->attach(*gpaL,1,7,1,1);	
	grid->attach(*gpaT,2,7,1,1);
	grid->attach(*yearL,1,8,1,1);
	grid->attach(*yearT,2,8,1,1);	
	grid->attach(*nextB,1,9,4,1);

	add(*grid);
}

GenInfoMenu::~GenInfoMenu()	{
		delete(grid);
		delete(nextB);
		delete(genInfoL);
		delete(firstNameT);
		delete(lastNameT);
		delete(stuNumT);
		delete(majorT);
		delete(yearT);
		delete(emailT);
		delete(gpaT);
		delete(cgpaT);
		delete(firstNameL);
		delete(lastNameL);
		delete(stuNumL);
		delete(majorL);
		delete(yearL);
		delete(emailL);
		delete(gpaL);
		delete(cgpaL);
}

//Returns frame if called
Gtk::Grid* GenInfoMenu::getGrid()	{
	return grid;
}

//Returns submit button if called
Gtk::Button* GenInfoMenu::getNext()	{
	return nextB;
}

//Returns firstName field if called
Gtk::Entry* GenInfoMenu::getFirstName()	{
	return firstNameT;
}

//Returns lastName field if called
Gtk::Entry* GenInfoMenu::getLastName()	{
	return lastNameT;
}

//Returns stuNum field if called
Gtk::Entry* GenInfoMenu::getStuNum()	{
	return stuNumT;
}

//Returns major field if called
Gtk::Entry* GenInfoMenu::getMajor()	{
	return majorT;
}

//Returns year field if called
Gtk::Entry* GenInfoMenu::getYear()	{
	return yearT;
}

//Returns email field if called
Gtk::Entry* GenInfoMenu::getEmail()	{
	return emailT;
}

//Returns gpa field if called
Gtk::Entry* GenInfoMenu::getGpa()	{
	return gpaT;
}

//Returns gpa field if called
Gtk::Entry* GenInfoMenu::getCgpa()	{
	return cgpaT;
}

//Sets firstName field to inputted string
void GenInfoMenu::setFirstName(string name)	{
	firstNameT->set_text(name);
}

//Sets lastName field to inputted string
void GenInfoMenu::setLastName(string name)	{
	lastNameT->set_text(name);	
}

//Sets stuNum field to inputted string
void GenInfoMenu::setStuNum(string num)	{
	stuNumT->set_text(num);
}

//Sets major field to inputted string
void GenInfoMenu::setMajor(string major)	{
	majorT->set_text(major);
}

//Sets year field to inputted string
void GenInfoMenu::setYear(string y)	{
	yearT->set_text(y);
}

//Sets email field to inputted string
void GenInfoMenu::setEmail(string r)	{
	emailT->set_text(r);
}

//Sets gpa field to inputted string
void GenInfoMenu::setGpa(string g)	{
	gpaT->set_text(g);
}

//Sets cgpa field to inputted string
void GenInfoMenu::setCgpa(string g)	{
	cgpaT->set_text(g);
}

//Checks student info currently entered to see if valid // not updated
bool GenInfoMenu::checkInfo()	{
	//Variable storing boolean result
	bool result = true;
	
	//Checks first name
	if(!Student::checkName(firstNameT->get_text()))	{
		firstNameT->set_text("");
		result = false;
	}

	//Checks last name
	if(!Student::checkName(lastNameT->get_text()))	{
		lastNameT->set_text("");
		result = false;
	}

	//Checks student number
	if(!Student::checkStuNum(stuNumT->get_text()))	{
		stuNumT->set_text("");
		result = false;
	}

	//Checks email address
	if(!Student::checkEmail(emailT->get_text()))	{
		emailT->set_text("");
		result = false;
	}

	//Checks major
	if(!Student::checkMajor(majorT->get_text()))	{
		majorT->set_text("");
		result = false;
	}

	//Checks year of standing
	if(!Student::checkStanding(yearT->get_text()))	{
		yearT->set_text("");
		result = false;
	}

	//Checks cgpa value
	if(!Student::checkCgpa(cgpaT->get_text()))	{
		cgpaT->set_text("");
		result = false;
	}

	//Checks gpa value
	if(!Student::checkGpa(gpaT->get_text()))	{
		gpaT->set_text("");
		result = false;
	}

	//Returns result
	return result;

}

void GenInfoMenu::setStudentInfo(Student* s)	{
	if(s == 0)	return;	
	
	stringstream l;
	setFirstName(s->getFirstName());
	setLastName(s->getLastName());
	setStuNum(s->getStuNum());
	setMajor(s->getMajor());
	if(s->getStanding() != -1)	{
		l.str("");
		l << s->getStanding();
		setYear(l.str());
	}
	setEmail(s->getEmail());
	if(s->getCgpa() != -1)	{
		l.str("");
		l << s->getCgpa();
		setCgpa(l.str());
	}
	if(s->getGpa() != -1)	{
		l.str("");
		l << s->getGpa();
		setGpa(l.str());
	}
}
