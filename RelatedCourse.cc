//RelatedCourse source file

//Include statements
#include "RelatedCourse.h"
#include <iostream>

//Default constructor
RelatedCourse::RelatedCourse(string name, string t, string y, string final)
	: Course(name, t, y), finalGrade(final)
{

}

//Returns final grade of the students course
string RelatedCourse::getFinalGrade()	{
	return finalGrade;
}

//Sets the final grade of the students course
void RelatedCourse::setFinalGrade(string final)	{
	finalGrade = final;
}

//Saves necessary info to file
void RelatedCourse::save()	{
	saveLog.open("saveLog.txt", ios::app);
	saveLog << "Rel" << "$" << getCourseName() << "$" << getTerm() << "$" << getYear() << "$" << getFinalGrade() << "$";
	saveLog.close();	
}
