//Course source file

//Include statements
#include "AssistantCourse.h"
#include <stdlib.h>

//Default AssistantCourse constructor using member initialation
AssistantCourse::AssistantCourse(string name, string t, string y, string sup)
	: Course::Course(name, t, y), supervisor(sup)
{	}

//Returns the name of the supervisor for the course
string AssistantCourse::getSupervisor()	{
	return supervisor;
}

//Sets the name of the supervisor for the course
void AssistantCourse::setSupervisor(string sup)	{
	supervisor = sup;
}

//Saves all necessary details to file
void AssistantCourse::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Ass" << "$" << getCourseName() << "$" << getTerm() << "$" << getYear() << "$" << getSupervisor() << "$";
	saveLog.close();	
}

//Checks the give supervisor
bool AssistantCourse::checkSupervisor(string s)	{
	if(s.find_first_of("0123456789!@#$%^&*()-_+=|/\\?><,{}[]+~`") != string::npos || s == "")	{
		return false;
	}
	unsigned found = s.find("..");
	if (found!=string::npos) return false;
 	return true;
}
