//VerificationMenu source file

//Include statements
#include "VerificationMenu.h"
#include <stdlib.h>
#include <stdio.h>

VerificationMenu::VerificationMenu()	{
	//Create box	
	box = new Gtk::VBox();

	numL = new Gtk::Label("ENTER YOUR STUDENT NUMBER:");
	numL->set_size_request(250, 30);
	
	numT = new Gtk::Entry();
	numT->set_size_request(250, 30);

	submit = new Gtk::Button("SUBMIT", false);
	submit->set_size_request(250, 30);

	//Add buttons to the box
	box->pack_start(*numL, Gtk::PACK_SHRINK, 0);
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

//Checks student number input
bool VerificationMenu::checkInput()	{
	if(!Student::checkStuNum(numT->get_text()))	{
		numT->set_text("");	
		return false;
	}
}

//Loads student if there is one with the entered student number
bool VerificationMenu::loadStudent(string num, Undergrad **undergrad, Grad **grad)	{
	string deleteLine;
	string line;
	bool loaded = false;

	ifstream myfile("saveLog.txt");
	ofstream newfile("temp.txt");
	if(!myfile.is_open())	return false;

	while(myfile.good() && getline(myfile, line))	{
		istringstream toParse (line, istringstream::in);
		string  type, firstName, lastName, stuNum , email;
	        
		getline(toParse, type, '$');

		if(type.compare("Und") == 0)	{
			string  major, standing, cgpa, gpa;
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,major,'$');
			getline(toParse,cgpa,'$');
			getline(toParse,gpa,'$');
			getline(toParse,standing,'$');
			cout << standing << " " << cgpa << " " << gpa << endl;
			if(stuNum == num)	{
				deleteLine = line;
				loaded = true;
				(*undergrad) = new Undergrad(firstName, lastName, stuNum, email, major, standing, cgpa, gpa);
				loadStudentInfo(toParse, **undergrad);
			}
		} else {
			string research, program, supervisor; 
			getline(toParse,firstName,'$');
			getline(toParse,lastName,'$');
			getline(toParse,stuNum,'$');
			getline(toParse,email,'$');
			getline(toParse,research,'$');
			getline(toParse,program,'$');
			getline(toParse,supervisor,'$');
			if(stuNum == num)	{
				deleteLine = line;
				loaded = true;
				(*grad) = new Grad(firstName, lastName, stuNum, email, research, program, supervisor);
				loadStudentInfo(toParse, **grad);
			}
		}
		if(deleteLine != line)	newfile << line << endl;
	}
	myfile.close();
	newfile.close();
	std::remove("saveLog.txt");
	std::rename("temp.txt", "saveLog.txt");
	return loaded;
}

//Loads all the information associated with the student
void VerificationMenu::loadStudentInfo(istringstream &toParse, Student &stu)	{
	string symbol;

	while(getline(toParse, symbol,'$'))	{
		if(symbol.compare("App") == 0)	{
			string appNum, status, course;
			getline(toParse, appNum, '$');
			getline(toParse, status,'$');
			getline(toParse, course,'$');
		
			stu.getApplications()->pushBack(new Application(course,-1, status, atoi(appNum.c_str())));
		}
		if(symbol.compare("Rel") == 0)	{
			string course, term, year, grade;
			getline(toParse, course, '$');
			getline(toParse, term,'$');
			getline(toParse, year,'$');
			getline(toParse, grade,'$');
		
			stu.getApplications()->back()->getRelated()->pushBack(new RelatedCourse(course, term, year, grade));
		}
		if(symbol.compare("Ass") == 0)	{
			string course, t, y, sup;
			getline(toParse, course, '$');
			getline(toParse, t,'$');
			getline(toParse, y,'$');
			getline(toParse, sup,'$');
		
			stu.getApplications()->back()->getAssisted()->pushBack(new AssistantCourse(course, t, y, sup));
		}
		if(symbol.compare("Wor") == 0)	{
			string title, duties, duration, start, end;
			getline(toParse, title, '$');
			getline(toParse, duration,'$');
			getline(toParse, start,'$');
			getline(toParse, end,'$');
			getline(toParse, duties,'$');
		
			stu.getApplications()->back()->getExperience()->pushBack(new WorkExperience(title, duties, duration, start, end));
		}
	}
}
