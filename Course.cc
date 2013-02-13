//Course source file

//Include statements
#include "Course.h"
#include <stdlib.h>

//Default constructor, with term and year defaulted to current time
Course::Course(string name, string t, int y)	
	: courseName(name), term(t), year(y)
{	}

//Default destructor
Course::~Course()	{

}

//Returns the title of the course
string Course::getCourseName()	{
	return courseName;
}

//Returns the term of the course
string Course::getTerm()	{
	return term;
}

//Returns the year of the course
int Course::getYear()	{
	return year;
}

//Sets the title of the course
void Course::setCourseName(string name)	{
	courseName = name;
}

//Sets term of the course
void Course::setTerm(string t)	{
	term = t;
}

//Sets year of the course
void Course::setYear(int y)	{
	year = y;
}

//Save data to output file
void Course::save()	{
	
}

int Course::checkYear(string s)	{
	float check;	
	
	if(s.find_first_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_+=|/\\?><,.{}[]+~`") != string::npos || s == "")	{
		return false;
	}

	check = atof(s.c_str());
	if(check > 2013 || check < 0)	{
		return false;
	}

	return true;
}
