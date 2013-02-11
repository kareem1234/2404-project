//Student header file

#include "Student.h"

#include <iostream>
using namespace std;

#include <stdlib.h>
#include <fstream>
ofstream saveLog;

//Default constructor
Student::Student()	{

	
	
}

//Destructor
Student::~Student()	{
	

}
// copy constructor
Student::Student(Student& other){
	applications = other.applications;
	firstName = other.getFirstName();
	lastName= other.getLastName(); 
	stuNum = other.getStuNum();
	email = other.getEmail();
	major = other.getMajor();
	year = other.getStanding();
	cgpa = other.getCgpa();
	gpa = other.getGpa();
}

//Returns complete name when called
string Student::getFirstName()	{
	return (firstName);
}
string Student::getLastName()	{
	return (lastName);
}

//Returns student number name when called
string Student::getStuNum()	{
	return stuNum;
}

//Returns email when called
string Student::getEmail()	{
	return email;
}

//Returns major when called
string Student::getMajor()	{
	return major;
}

//Returns year of standing when called
int Student::getStanding()	{
	return year;
}

//Returns cgpa when called
float Student::getCgpa()	{
	return cgpa;
}

//Returns gpa when called
float Student::getGpa()	{
	return gpa;
}

//Returns head of list of applications
Application* Student::getApplications()	{
	Application* app = new Application;
	applications.popFront(app);
	return app;
}

//Sets first and last name with given strings
void Student::setName(string name1, string name2)	{
	firstName = name1;
	lastName = name2;
}

//Sets student number to given string
void Student::setStuNum(string num)	{
	stuNum = num;
}

//Sets email to given string
void Student::setEmail(string emailAdd)	{
	email = emailAdd;
}

//Sets major to given string
void Student::setMajor(string study)	{
	major = study;
}

//Sets year of standing to given integer
void Student::setStanding(string standing)	{
	int newYear;
	newYear = atoi(standing.c_str());
	year = newYear;
}

//Sets cgpa to given float
void Student::setCgpa(string mark)	{
	float newMark;
	newMark = atof(mark.c_str());
	cgpa = newMark;
}

//Sets gpa to given float
void Student::setGpa(string mark)	{
	float newMark;
	newMark = atof(mark.c_str());
	gpa = newMark;
}

//Save function saves newest application under the student
void Student::save()	{
	saveLog.open("saveLog.txt", ios::app);	
	saveLog << firstName + " " << lastName << " " << stuNum << " " << email;
        saveLog << " " << major << " " << cgpa << " " << gpa;
	//must fix saving for each application in que
	//application->save();
	saveLog << endl;
}

//Check functions check all data members for correct values
bool Student::checkName(string name)	{
	//Check that the name doesn't have numbers
	if(!validString(name))	{
		return false;
	}
 	return true;
}
int Student::getNumApps(){
	return applications.length();
}
//Checks student number for weird values
bool Student::checkStuNum(string num)	{
	float check;
	if(!validInt(num))	{
		return false;
	}

	if(num.length() < 9 || num.length() > 9)	{
		return false;
	}
	return true;
}

//Checks email for proper string containing '@'
bool Student::checkEmail(string emAdd)	{ 
	if((emAdd.find("@carleton.ca") != string::npos && emAdd.find("@carleton.ca") != 0) || (emAdd.find("@cmail.carleton.ca") != string::npos && emAdd.find("@cmail.carleton.ca") != 0))	{
		return true;
	}
 	return false;
}

//Checks major has no weird values
bool Student::checkMajor(string study)	{
	//Check theres no characters except letters
	if(!validString(study))	{
		return false;
	}
 	return true;
}

//Checks standing is a number and is in the range 1-4
bool Student::checkStanding(string standing)	{
	int check;
	if(!validInt(standing))	{ 
		return false;
	}
	check = atof(standing.c_str());
	if(check > 4 && check < 1)	{
		return false;
	}
	return true;
}

//Checks cgpa is a number and is the range 0-12
bool Student::checkCgpa(string mark)	{
	float check;
	if(!validFloat(mark))	{
		return false;
	}
	check = atof(mark.c_str());
	if(check > 12 && check < 0)	{
		return false;
	}
	return true;
}

//Checks gpa is a number and is the range 0-12
bool Student::checkGpa(string mark)	{
	float check;
	if(!validFloat(mark)) 	{
		return false;
	}
	check = atof(mark.c_str());
	if(check > 12 && check < 0)	{
		return false;
	}
	return true;
}

//Checks string has no funny characters or numbers
bool Student::validString(string s)	{
	if(s.find_first_of("0123456789!@#$%^&*()-_+=|/\\?><,.{}[]+~`") != string::npos || s == " ")	{
		return false;
	}
 	return true;
}

//Checks string is a valid integer with no spaces or characters
bool Student::validInt(string s)		{
	if(s.find_first_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_+=|/\\?><,.{}[]+~`") != string::npos || s == " ")	{
		return false;
	}
	return true;
}

//Checks string is a valid float with no spaces or characters except '.'
bool Student::validFloat(string s)		{
	if(s.find_first_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_+=|/\\?><,{}[]+~`") != string::npos || s == " ")	{
		return false;
	}
	return true;
}
