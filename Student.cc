//Student header file

#include "Student.h"

#include <iostream>
using namespace std;
#include <stdlib.h>

//Default constructor
Student::Student(string f, string l, string s, string e)
	: firstName(f), lastName(l), stuNum(s), email(e)
{	}

//Destructor
Student::~Student()	{
	applications.clear();
}

//Returns complete name when called
string Student::getFirstName()	{
	return (firstName);
}

//Returns last name when called
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

//Returns head of list of applications
myQ<Application>* Student::getApplications()	{
	return &applications;
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

//Save function saves all application under the student
void Student::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Stu" << "$" << firstName << "$" << lastName << "$" << stuNum << "$" << email << "$";
	saveLog.close();
	applications.save();
	saveLog << endl;
	saveLog.close();
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

//Checks string has no funny characters or numbers
bool Student::validString(string s)	{
	if(s.find_first_of("0123456789!@#$%^&*()-_+=|/\\?><,.{}[]~`;:'") != string::npos || s == "")	{
		return false;
	}
 	return true;
}

//Checks string is a valid integer with no spaces or characters
bool Student::validInt(string s)		{
	if(s.find_first_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_+=|/\\?><,.{}[]+~`") != string::npos || s == "")	{
		return false;
	}
	return true;
}

//Checks string is a valid float with no spaces or characters except '.'
bool Student::validFloat(string s)		{
	if(s.find_first_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_+=|/\\?><,{}[]+~`") != string::npos || s == "")	{
		return false;
	}

	unsigned found = s.find("..");
	if (found != string::npos) return false;
	
	return true;
}
