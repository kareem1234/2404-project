//Course source file

//Include statements
#include "AssistantCourse.h"
using namespace std;
//Default AssistantCourse constructor using member initialation
AssistantCourse::AssistantCourse(string name, string t, int y, string sup)
	: Course::Course(name, t, y), supervisor(sup)
{	}

//Default destructor
AssistantCourse::~AssistantCourse()	{

}

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
	saveLog<<" "<<"A"<<" "<<getCourseName()<<" "<<getTerm();
	saveLog<<" "<<getYear()<<" "<<getSupervisor();	
	

}
