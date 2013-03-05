//GenInfoMenu source file

//Include statements
#include "GenInfoMenu.h"
#include "Student.h"
#include <sstream>

//Default constructor
GenInfoMenu::GenInfoMenu(string type)	{
	//Create frame
	grid = new Gtk::Grid();

	//Create labels
	genInfoL = new Gtk::Label("GENERAL INFO");
	genInfoL->set_size_request(150, 30);

	lastNameL = new Gtk::Label("LAST NAME");
	lastNameL->set_size_request(70, 30);
	
	firstNameL = new Gtk::Label("FIRST NAME");
	firstNameL->set_size_request(70, 30);

	stuNumL = new Gtk::Label("STUDENT NUMBER");
	stuNumL->set_size_request(70, 30);

	emailL = new Gtk::Label("EMAIL");
	emailL->set_size_request(70, 30);

	if(type == "Undergrad")	{
		gpaL = new Gtk::Label("GPA");
		gpaL->set_size_request(70, 30);
	
		cgpaL = new Gtk::Label("CGPA");
		cgpaL->set_size_request(70, 30);
	
		yearL = new Gtk::Label("YEAR");
		yearL->set_size_request(70, 30);

		majorL = new Gtk::Label("MAJOR");
		majorL->set_size_request(70, 30);

		researchL = 0;
		programL = 0;
		supervisorL = 0;		
	}

	if(type == "Grad")	{
		researchL = new Gtk::Label("RESEARCH AREA");
		researchL->set_size_request(70, 30);
	
		programL = new Gtk::Label("PROGRAM");
		programL->set_size_request(70, 30);
	
		supervisorL = new Gtk::Label("SUPERVISOR");
		supervisorL->set_size_request(70, 30);

		gpaL = 0;
		cgpaL = 0;
		majorL = 0;
		yearL = 0;
	}
	
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

	emailT = new Gtk::Entry();
	emailT->set_size_request(70,30);

	if(type == "Undergrad")	{
		majorT = new Gtk::Entry();
		majorT->set_size_request(70,30);
	
		yearT = new Gtk::Entry();
		yearT->set_size_request(70,30);

		gpaT = new Gtk::Entry();
		gpaT->set_size_request(70,30);

		cgpaT = new Gtk::Entry();
		cgpaT->set_size_request(70,30);

		researchT = 0;
		programT = 0;
		supervisorT = 0;
	}
	if(type == "Grad")	{
		researchT = new Gtk::ComboBoxText();
		researchT->set_size_request(70,30);

		programT = new Gtk::ComboBoxText();
		programT->set_size_request(70,30);

		supervisorT = new Gtk::Entry();
		supervisorT->set_size_request(70,30);

		research_refTreeModel = Gtk::ListStore::create(research_Columns);
		researchT->set_model(research_refTreeModel);

		program_refTreeModel = Gtk::ListStore::create(program_Columns);
		programT->set_model(program_refTreeModel);

		Gtk::TreeModel::Row row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "Algorithms and Complexity";
		row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "Knowledge Based and Intelligent Systems";
		row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "Software Engineering";
		row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "Parallel and Distributed Systems";
		row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "Information Systems Security and Applied Cryptography";
		row = *(research_refTreeModel->append());
		row[research_Columns.m_col_value] = "BioInformatics and Biomedical Computing";

		Gtk::TreeModel::Row row1 = *(program_refTreeModel->append());
		row1[program_Columns.m_col_value] = "MCS";
		row1 = *(program_refTreeModel->append());
		row1[program_Columns.m_col_value] = "PhD";

		majorT = 0;
		yearT = 0;
		gpaT = 0;
		cgpaT = 0;
	}
	
	//Position them all
	grid->attach(*genInfoL,1,0,2,1);
	grid->attach(*firstNameL,1,1,1,1);
	grid->attach(*firstNameT,2,1,1,1);
	grid->attach(*lastNameL,1,2,1,1);
	grid->attach(*lastNameT,2,2,1,1);	
	grid->attach(*stuNumL,1,3,1,1);	
	grid->attach(*stuNumT,2,3,1,1);
	grid->attach(*emailL,1,4,1,1);	
	grid->attach(*emailT,2,4,1,1);
	
	if(type == "Undergrad")	{
		grid->attach(*majorL,1,5,1,1);	
		grid->attach(*majorT,2,5,1,1);
		grid->attach(*cgpaL,1,6,1,1);	
		grid->attach(*cgpaT,2,6,1,1);	
		grid->attach(*gpaL,1,7,1,1);	
		grid->attach(*gpaT,2,7,1,1);
		grid->attach(*yearL,1,8,1,1);
		grid->attach(*yearT,2,8,1,1);	
		grid->attach(*nextB,1,9,2,1);
	}
	if(type == "Grad")	{
		grid->attach(*researchL,1,5,1,1);	
		grid->attach(*researchT,2,5,1,1);	
		grid->attach(*programL,1,6,1,1);	
		grid->attach(*programT,2,6,1,1);
		grid->attach(*supervisorL,1,7,1,1);
		grid->attach(*supervisorT,2,7,1,1);	
		grid->attach(*nextB,1,8,2,1);
	}

	add(*grid);
}

//Default destructor
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
	cout << "Deleted general info" << endl;
	delete(majorL);
	delete(yearL);
	delete(emailL);
	delete(gpaL);
	delete(cgpaL);
	cout << "Deleted undergrad info" << endl;
	delete(researchL);
	delete(researchT);
	delete(programL);
	delete(programT);
	delete(supervisorL);
	delete(supervisorT);
	cout << "Finished dtor" << endl;
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

//Returns the research combo box when called
Gtk::ComboBoxText* GenInfoMenu::getResearch()	{
	return researchT;
}

//Returns the program combo box when called
Gtk::ComboBoxText* GenInfoMenu::getProgram()	{
	return programT;
}

//Returns the supervisor combo box when called
Gtk::Entry* GenInfoMenu::getSupervisor()	{
	return supervisorT;
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

//Sets selected research field to inputted string
void GenInfoMenu::setResearch(string r)	{
	researchT->set_active_text(r);
}

//Sets selected program type to inputted string
void GenInfoMenu::setProgram(string p)	{
	programT->set_active_text(p);
}

//Sets supervisor field to inputted string
void GenInfoMenu::setSupervisor(string s)	{
	supervisorT->set_text(s);
}

//Checks student info currently entered to see if valid // not updated
bool GenInfoMenu::checkInfo(string type)	{
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

	if(type == "Undergrad")	{
		//Checks major
		if(!Undergrad::checkMajor(majorT->get_text()))	{
			majorT->set_text("");
			result = false;
		}

		//Checks year of standing
		if(!Undergrad::checkStanding(yearT->get_text()))	{
			yearT->set_text("");
			result = false;
		}

		//Checks cgpa value
		if(!Undergrad::checkCgpa(cgpaT->get_text()))	{
			cgpaT->set_text("");
			result = false;
		}

		//Checks gpa value
		if(!Undergrad::checkGpa(gpaT->get_text()))	{
			gpaT->set_text("");
			result = false;
		}
	}
	if(type == "Grad")	{
		//Checks research area
		if(researchT->get_active_row_number() == -1)	{
			result = false;
		}
		//Checks program
		if(programT->get_active_row_number() == -1)	{
			result = false;
		}
		//Checks supervisor
		if(!Grad::checkSupervisor(supervisorT->get_text()))	{
			supervisorT->set_text("");
			result = false;
		}
	}

	cout << "Result is: " << result << endl;

	//Returns result
	return result;

}

//Sets the incoming student values from form currently displayed
void GenInfoMenu::setUndergradInfo(Undergrad* s)	{
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

//Sets the incoming student values from form currently displayed
void GenInfoMenu::setGradInfo(Grad* s)	{
	if(s == 0)	return;	

	setFirstName(s->getFirstName());
	setLastName(s->getLastName());
	setStuNum(s->getStuNum());
	setEmail(s->getEmail());
	setResearch(s->getResearch());
	setProgram(s->getProgram());
	setSupervisor(s->getSupervisor());
}
