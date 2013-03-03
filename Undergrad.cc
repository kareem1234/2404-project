//Undergrad source file

//Include statements
#include "Undergrad.h"
#include <iostream>
using namespace std;

#include <stdlib.h>
#include <string>

//Default constructor
Undergrad::Undergrad()
	: Student()	
{
	year = -1;
	cgpa = -1;
	gpa = -1;
}

//Default destructor
Undergrad::~Undergrad()	{

}

//Returns major when called
string Undergrad::getMajor()	{
	return major;
}

//Returns year of standing when called
int Undergrad::getStanding()	{
	return year;
}

//Returns cgpa when called
float Undergrad::getCgpa()	{
	return cgpa;
}

//Returns gpa when called
float Undergrad::getGpa()	{
	return gpa;
}

//Sets major to given string
void Undergrad::setMajor(string study)	{
	major = study;
}

//Sets year of standing to given integer
void Undergrad::setStanding(string standing)	{
	int newYear;
	newYear = atoi(standing.c_str());
	year = newYear;
}

//Sets cgpa to given float
void Undergrad::setCgpa(string mark)	{
	float newMark;
	newMark = atof(mark.c_str());
	cgpa = newMark;
}

//Sets gpa to given float
void Undergrad::setGpa(string mark)	{
	float newMark;
	newMark = atof(mark.c_str());
	gpa = newMark;
}

//Save function saves all application under the student
void Undergrad::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Und" << "$" << getFirstName() << "$" << getLastName() << "$" << getStuNum() << "$" << getEmail() << "$" << major << "$" << cgpa << "$" << gpa << "$"<< year << "$";
	saveLog.close();
	getApplications()->save();

	saveLog.open("saveLog.txt", ios::app);
	saveLog << endl;
	saveLog.close();
}

//Checks major has no weird values
bool Undergrad::checkMajor(string study)	{
	//Check theres no characters except letters
	if(!validString(study))	{
		return false;
	}
 	return true;
}

//Checks standing is a number and is in the range 1-4
bool Undergrad::checkStanding(string standing)	{
	int check;
	if(!validInt(standing))	{ 
		return false;
	}
	check = atof(standing.c_str());
	if(check > 4 || check < 1)	{
		return false;
	}
	return true;
}

//Checks cgpa is a number and is the range 0-12
bool Undergrad::checkCgpa(string mark)	{
	float check;
	if(!validFloat(mark))	{
		return false;
	}
	check = atof(mark.c_str());
	if(check > 12 || check < 0)	{
		return false;
	}
	return true;
}

//Checks gpa is a number and is the range 0-12
bool Undergrad::checkGpa(string mark)	{
	float check;
	if(!validFloat(mark)) 	{
		return false;
	}
	check = atof(mark.c_str());
	if(check > 12 || check < 0)	{
		return false;
	}
	return true;
}
